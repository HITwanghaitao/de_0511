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
	int N_population = 200; //群体规模参数M，一般介于 5×n与 10×n之间，但不能少于 4×n
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
	vector<int> random_sort(vector<int> array);//随机排序，一维数组
	vector<int> GetRandomPs();
	void SetParameter(double (*objf)(vector<double> x), vector<double (*)(vector<double> X)> obj_gs, vector<vector<double>> bounds);//设定参数
	void initialize();//初始化，产生初始种群
	void mutate(); //变异
	void crossover(vector<double> x); //交叉
	void choice(int j); //选择
	void run();

	double (*fun)(vector<double> x); //原始函数
	double func(vector<double> X, int generation); //带有惩罚项的增广目标函数
	vector<double (*)(vector<double> X)> gfunc;
	int gfunc_number = 0;

};
double function_test(vector<double> x);