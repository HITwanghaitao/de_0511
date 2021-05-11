#include "de.h"

double DE::rand_0_1(void) //����0-1����
{
	return double(rand()) / double(RAND_MAX);
}

vector<int> DE::random_sort(vector<int> array)//�������һά����
{
	vector<int> r; //���ڴ洢������������

	int m = array.size(); //�������ݵĳ���

	vector<int>::iterator  iter = array.begin(); //����ָ��

	//srand(time(NULL)); //���������
	//iter = array.begin();
	int flag;
	int m_change;
	for (int j = 0; j < m; j++)
	{
		iter = array.begin();
		int m_change = array.size();
		//cout << m_change << " ";

		// �����ڳ���
		//
		flag = floor((double(rand()) / (double(RAND_MAX) + 1)) * m_change); //��������(0,m_change)�ڵ����������,flag���ܵ���m_change
		//cout << flag << endl;
		//cout << *(iter + flag) << endl;
		r.push_back(*(iter + flag));
		array.erase(iter + flag);

	}
	//cout << endl;
	return r;
}
vector<int> DE::GetRandomPs()
{
	vector<int> ps(3);
	vector<int> r = random_sort(sort_0_N_population);
	ps[0] = r[0];
	ps[1] = r[1];
	ps[2] = r[2];
	return ps;
}
void DE::SetParameter(double (*objf)(vector<double> x), vector<double (*)(vector<double> X)> obj_gs,vector<vector<double>> bounds)
{
	srand(12345);
	fun = objf;
	gfunc_number = obj_gs.size();
	gfunc.resize(gfunc_number);
	for (int j = 0; j < gfunc_number; j++)
	{
		gfunc[j] = obj_gs[j];
	}
	Dimension = bounds.size();
	x_mutated.resize(Dimension);
	x_crossoverd.resize(Dimension);
	xlow.resize(Dimension);
	xhigh.resize(Dimension);
	sort_0_N_population.resize(N_population);
	for (int j = 0; j < N_population; j++)
	{
		sort_0_N_population[j] = j;
	}

	for (int j = 0; j < Dimension; j++)
	{
		xlow[j] = bounds[j][0];
		xhigh[j] = bounds[j][1];
	}
	cout << "���ò������" << endl;
}

void DE::initialize()//��ʼ����������ʼ��Ⱥ
{
	Xpop.resize(N_population, vector<double>(Dimension));
	Xpop_g.resize(N_population, vector<double>(Dimension));
	x_best.resize(Dimension);
	for (int j = 0; j < N_population; j++)
	{
		for (int k = 0; k < Dimension; k++)
		{
			Xpop[j][k] = xlow[k] + rand_0_1() * (xhigh[k] - xlow[k]);
		}
	}
	x_best = Xpop[0]; //��ʼ��x_best
	cout << "��ʼ�����" << endl;
}
void DE::mutate() //����, DE/rand/1/bin
{

	vector<int> ps = GetRandomPs();
	double xp1;
	double xp2;
	double xp3;
	int p1 = ps[0];
	int p2 = ps[1];
	int p3 = ps[2];
	double temp;
	for (int j = 0; j < Dimension; j++)
	{

		xp1 = Xpop[p1][j];
		xp2 = Xpop[p2][j];
		xp3 = Xpop[p3][j];
		//x_mutated[j] = xp1 + F * (xp2 - xp3);
		temp = xp1 + F * (xp2 - xp3);
		if (temp<xlow[j] || temp>xhigh[j])
		{
			//cout << "    �����߽�" << endl;
			temp = xlow[j] + (xhigh[j] - xlow[j]) * rand_0_1();
		}
		x_mutated[j] = temp;
		//ȷ���²����ı������������߽�
	}
}
void DE::crossover(vector<double> x) //Ⱥ���ڵĵ�һ����
{
	for (int j = 0; j < Dimension; j++)
	{
		if (rand_0_1() <= Cr)
			x_crossoverd[j] = x_mutated[j];
		else
			x_crossoverd[j] = x[j];
	}
}

void DE::choice(int j) //Ⱥ���ڵĵ�j������
{
	vector<double> xi = Xpop[j];
	vector<double> vi = x_crossoverd;
	if (func(vi,gnumber) < func(xi,gnumber))
	{
		Xpop_g[j] = vi;
		if (func(vi,gnumber) < func(x_best,gnumber))
		{
			x_best = vi;
			y_best = func(vi,gnumber);
			cout << y_best << endl;
		}
	}
	else
		Xpop_g[j] = xi;
	//cout << func(Xpop_g[j]) << endl;

}
void DE::run()
{
	//ofstream out("f1_fitness.txt");
	for (int j = 0; j < N_generation; j++)
	{
		gnumber = j + 1;
		for (int k = 0; k < N_population; k++)
		{
			mutate();
			crossover(Xpop[k]);
			choice(k);
		}
		Xpop = Xpop_g;
		//out << fun(x_best) << '\t' << func(x_best, gnumber) << '\t' << gfunc[0](x_best) << endl;
		cout << "��" << j + 1 << "�����" << endl;
	}
	//out.close();
	for (int j = 0; j < x_best.size(); j++)
	{
		cout << x_best[j] << " ";
	}
	cout << endl;
	cout << y_best << endl;
}
/*
double function_test(vector<double> x)
{
	double y = 0;
	for (int j = 0; j < x.size(); j++)
	{
		y += pow((x[j] - 4.555-j), 2);
	}
	return y;
}
*/
/*
double function_test(vector<double> x)
{
	double y;
	double s = 2.125683;
	//y = sin(x[0] - s) / sqrt(pow(x[0], 2) + pow(s, 2));
	y = abs(sin(x[0] - s));
	return y;
}
*/
double function_test(vector<double> x)
{
	double y;
	double temp0 = pow(x[0], 2) + pow(x[1], 2);
	double temp1 = pow(sin(sqrt(temp0)), 2) - 0.5;
	double temp2 = pow(1 + 0.001 * pow(temp0, 2), 2);
	y = 0.5 + temp1 / temp2;
	return y;
}
double DE::func(vector<double> X, int generation)
{
	double p = 0; //�ͷ���
	double temp = 0;
	for (int j = 0; j < gfunc_number; j++)
	{
		temp = gfunc[j](X);
		if (temp < 0)
		{
			p += pow(temp, 2);
			//cout << "p=" << temp << endl;
		}
		else
		{
			//cout << "p=" << p << endl;
		}
	}
	return fun(X) + 0.1 * pow(2, generation - 1) * p;
}