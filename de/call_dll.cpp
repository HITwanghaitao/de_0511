#include "call_dll.h"
using namespace std;

ptrSub dll_sim_model(HMODULE hMod)
{
    ptrSub sim_model = NULL;
    if (hMod != NULL)
    {
        sim_model = (ptrSub)GetProcAddress(hMod, "sim_model_DLL");
        if (sim_model == NULL)
        {
            throw "the function was not fund, but the dll was found";
        }
    }
    else
    {
        throw "the DLL was not found";
    }
    return sim_model;
    /* //ÓÃÓÚ²âÊÔµ÷ÓÃµÄ¾ä±ú
    vector<double> xin10 = { 0.0174603,0.422222,1.1,1.69365,2.35873,3.0746,3.38889,3.87619,4.40159,4 };
    vector<double> cin7 = { 15, 21, 0.403, 2, 0.04, 0.04, 1.2 };
    int choice = 1;
    cout << sim_model(xin10, cin7, choice) << endl;
    */
}