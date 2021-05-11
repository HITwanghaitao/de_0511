#pragma once
#include<vector>
#include <iostream>

#include <iostream>
#include <vector>        //提供向量头文件
#include <algorithm>     // 算法头文件，提供迭代器
#include <fstream>       //提供文件头文件
#include <iomanip>       //C++输出精度控制需要
#include <string>
using namespace std;


vector<double> random_sort(vector<double> array);//随机排序，一维数组
vector<vector<double>> random_sort_N_D(vector<vector<double>> d); //随机排序，二维数组，对于列向量内的数据进行排序

vector<vector<double>> u_lhs(int N,int D); //内部初始抽样，用于拉丁超立方
vector<vector<double>> u_lhs_bounds(int N, int D, vector<vector<double>> bounds);
vector<vector<double>> lhs(int N,int D); //拉丁超立方抽样（完整）
vector<vector<double>> lhs_bounds(int N, int D, vector<vector<double>> bounds);
