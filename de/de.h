#pragma once
#include<iostream>
#include<random>
#include<vector>
#include<string>
#include <cmath>
#include <fstream>

using namespace std;
class DE
{
public:
	int N_population = 200; //Ⱥ���ģ����M��һ����� 5��n�� 10��n֮�䣬���������� 4��n
	int N_generation = 500;
	int Dimension;
	double F = 0.5;
	double Cr = 0.6;
	vector<double> xlow = {};
	vector<double> xhigh = {};

	int gnumber = 0;

	vector<vector<double>> Xpop;
	vector<vector<double>> Xpop_g;
	vector<int> sort_0_N_population = {};
	vector<double> x_mutated;
	vector<double> x_crossoverd;
	vector<double> x_best;
	double y_best;
	double rand_0_1(void);
	vector<int> random_sort(vector<int> array);//�������һά����
	vector<int> GetRandomPs();
	void SetParameter(double (*objf)(vector<double> x), vector<double (*)(vector<double> X)> obj_gs, vector<vector<double>> bounds);//�趨����
	void initialize();//��ʼ����������ʼ��Ⱥ
	void mutate(); //����
	void crossover(vector<double> x); //����
	void choice(int j); //ѡ��
	void run();

	double (*fun)(vector<double> x); //ԭʼ����
	double func(vector<double> X, int generation); //���гͷ��������Ŀ�꺯��
	vector<double (*)(vector<double> X)> gfunc;
	int gfunc_number = 0;

};
double function_test(vector<double> x);