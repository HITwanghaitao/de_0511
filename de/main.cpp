#include <iostream>
#include "call_dll.h"
#include "de.h"
#include "LHS_sample.h"
#include <fstream>

using namespace std;
HMODULE hMod = LoadLibrary(L"Dll_EMG_MODEL.dll"); //加载动态链接库DLL
ptrSub sim_model = dll_sim_model(hMod); //获取函数句柄
vector<vector<double>> bounds_x = { {0,0.1},{0.2,0.6},{0.7,1.1},{1.3,1.7},{2.2,2.6},{2.7,3.1},{3.3,3.7},{3.8,4.2},{4.3,4.7},{4,6} };
vector<vector<double>> bounds_c = { {12,18},{15,25}, {0.2,0.6},{1.5,2.5},{0.03,0.05},{0.02,0.05},{1.0,1.3} };
vector<vector<double>> bounds_c_s = { {0.3,0.5},{1.7,2.3},{0.035,0.045},{0.035,0.045},{1.1,1.2} };



vector<double> x1 = { 0.0993332 ,0.599634, 1.09983 ,1.669 ,2.20618, 2.70387 ,3.30494 ,3.81053, 4.68607, 5.99815 };
vector<double> x2 = { 0.0997369 ,0.599519 ,1.09954 ,1.69944 ,2.59956 ,2.82059 ,3.3005 ,3.80882, 4.30493 ,4.0014 };
vector<double> x3 = { 0.00382948 ,0.205105 ,0.703729 ,1.30423, 2.37943 ,3.09964 ,3.69936, 4.1991, 4.69236, 4 };

double obj_emg(vector<double> x, vector<double> c,int choice)
{
	/*
	vector<double> c7(7);
	c7[0] = 15;
	c7[1] = 21;
	for (int j = 0; j < c.size(); j++)
	{
		c7[j + 2] = c[j];
	}*/
	return -sim_model(x, c, choice);
}
double obj_emg1(vector<double> x)
{
	vector<double> c = { 15,21,0.4,2,0.04,0.04,1.15 };
	return -sim_model(x, c, 2); //最大速度
}
double obj_emg2(vector<double> x)
{
	vector<double> c = { 15,21,0.4,2,0.04,0.04,1.15 };
	return -sim_model(x, c, 3); //最大效率
}
double obj_emg3(vector<double> x)
{
	vector<double> c = { 15,21,0.4,2,0.04,0.04,1.15 };
	return sim_model(x, c, 4); //最小累计热量
}

double obj_g(vector<double> x) //惩罚项
{
	vector<double> c = { 15,21,0.4,2,0.04,0.04,1.15 };
	return 450000 - sim_model(x, c, 1); //最大电流不能超过450KA
}
vector<double (*)(vector<double> X)> obj_gs = { obj_g }; //惩罚项

void test_de()
{
	DE de;

	de.SetParameter(obj_emg1, obj_gs,bounds_x);
	de.initialize();
	de.run();
}
void fluctuate_test()
{
	int N = 10000;
	int D = 5;
	vector<vector<double>> C = lhs_bounds(N, D, bounds_c_s);
	vector<double> c7(7);
	c7[0] = 15;
	c7[1] = 21;
	int over_n = 0;
	double fn;
	double Imax;
	ofstream out("f2_fluctuate.txt");
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < C[j].size(); k++)
		{
			c7[k + 2] = C[j][k];
		}
		Imax = sim_model(x2, c7, 1);
		fn = obj_emg(x2, c7, 3);
		cout << fn <<  '\t' << Imax << endl;
		out << fn << '\t' << Imax << endl;
		if (Imax > 450000)
		{
			cout << "过界" << endl;
			over_n += 1;
		}
	}
	out.close();
	cout << "越界数量=" << over_n << endl;
}
void cr_test()
{
	int N = 10000;
	int D1 = 10;
	int D2 = 5;
	vector<vector<double>> X = lhs_bounds(N, D1, bounds_x);
	vector<vector<double>> C = lhs_bounds(N, D2, bounds_c_s);
	vector<double> c7(7);
	c7[0] = 15;
	c7[1] = 21;
	double Imax, Vend, Eff, Hot;
	ofstream out("cr_y_4_min.txt");
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < C[j].size(); k++)
		{
			c7[k + 2] = C[j][k];
		}
		Imax = sim_model(X[j], c7, 1);
		Vend = sim_model(X[j], c7, 2);
		Eff = sim_model(X[j], c7, 3);
		Hot = sim_model(X[j], c7, 4);
		cout << Imax << '\t' << Vend << '\t' << Eff << '\t' << Hot << endl;
		out << -Imax << '\t' << -Vend << '\t' << -Eff << '\t' << Hot << endl;
	}
	out.close();
}

int main()
{

	//test_de();
	//fluctuate_test();
	cr_test();

}
