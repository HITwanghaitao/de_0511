#pragma once
#include <windows.h>
#include <vector>
using namespace std;

typedef double(*ptrSub)(vector<double>, vector<double>, int);
ptrSub dll_sim_model(HMODULE hMod); //HMODULE �Ǵ���Ӧ�ó��������ģ��