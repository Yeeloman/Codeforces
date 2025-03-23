#include <iostream>
#include <vector>

int handleFour(int k, int n, std::vector<int>inpts)
{
    int cmpt = 1000;
    int tmp_two;
    int tmp;
    int modulo_zero = 0, modulo_one = 0;
    
    if(n == 1)
    {
        if(inpts[0] % k == 0) return 0;
        tmp = inpts[0] % k;
        tmp = k - tmp;
        return tmp;
    } 

    for(auto el : inpts)
    {
        if(el % 4 == 0) return 0;
        tmp = el % 2;
        tmp_two = el % 4; 
        tmp_two = 4 - tmp_two;
        // std::cout<<"this is el"<<el<<" now its tmptwo"<<tmp_two<<std::endl;

        if(tmp_two < cmpt) cmpt = tmp_two;
        if(tmp == 0) modulo_zero++; 
        if(tmp == 1) modulo_one++;
        if(modulo_zero >= 2) return 0;
    }
    if(modulo_zero >= 1 && modulo_one >= 1) return std::min(1, cmpt);
    return std::min(cmpt, 2);
}

int inputHandler(int k, int n, std::vector<int> inpts) 
{

    int cmpt = 1000;
    int tmp;

    if(k == 4)
    {
        return handleFour(k, n, inpts);
    }

    for(auto el : inpts){
        if(el == k) return 0;
        tmp = el % k;
        tmp = k - tmp;
        if (tmp == k) return 0;
        if(tmp < cmpt){
            cmpt = tmp;
        }
    }
    return cmpt;
}

int main() {
    int t, n, k;
    std::vector<int> results;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin>>n>>k;
        std::vector<int> inputs(n);
        for(int j=0; j < n; j++){
            std::cin >> inputs[j];
        }
        // for(auto el : inputs) 
        // {
        //     std::cout<<el<<std::endl;
        // }
        results.push_back(inputHandler(k, n, inputs));
    }

    for(auto el : results)
    {
        std::cout<<el<<std::endl;
    }
    return 0;
}