#pragma once
#include<vector>
#include <iostream>

#include <iostream>
#include <vector>        //�ṩ����ͷ�ļ�
#include <algorithm>     // �㷨ͷ�ļ����ṩ������
#include <fstream>       //�ṩ�ļ�ͷ�ļ�
#include <iomanip>       //C++������ȿ�����Ҫ
#include <string>
using namespace std;


vector<double> random_sort(vector<double> array);//�������һά����
vector<vector<double>> random_sort_N_D(vector<vector<double>> d); //������򣬶�ά���飬�����������ڵ����ݽ�������

vector<vector<double>> u_lhs(int N,int D); //�ڲ���ʼ��������������������
vector<vector<double>> u_lhs_bounds(int N, int D, vector<vector<double>> bounds);
vector<vector<double>> lhs(int N,int D); //����������������������
vector<vector<double>> lhs_bounds(int N, int D, vector<vector<double>> bounds);
