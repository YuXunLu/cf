#include <iostream>
#include <fstream>
#include <stdlib.h>
#define SUBMISSION_VER 0
bool judge(int n, int a, int b, int c, int d)
{
    bool result = false;
    int min_weight, max_weight; 
    int min_cap, max_cap; 

    min_weight = n * (a-b);
    max_weight = n * (a+b);

    min_cap = c-d; 
    max_cap = c+d;

    if (min_weight >= min_cap)
    {
        if (min_weight <= max_cap)
            result = true;
        else
            result = false;
    }
    else // min_weight < min_cap
    {
        if (max_weight >= min_cap)
            result = true;
        else
            result = false;
    }
    

    return result;
}
int main(int argc, char* argv[]){
    int a,b,c,d;
    int n, t;
#ifndef SUBMISSION_VER
    freopen("637D2A.in", "r", stdin);
    freopen("637D2A.out", "w", stdout);
#endif
    std::cin >> t;

    for(int i=0; i<t; i++){
        std::cin >> n >> a >> b >> c >> d;
        bool res = judge(n,a,b,c,d);
        if (res)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
        
    }
    return 0;
}