#include <iostream>
#include <vector>


int gwd_process(int la, int ra, int lb, int rb)
{
    if(la == lb && ra == rb) return ra-la;
    if(std::max(la, lb) > std::min(ra, rb)) return 1;
    if((la <= lb && rb <= ra) ||(lb <= la && ra <= rb)){
        if(rb == ra || la == lb) return std::min(rb,ra) - std::max(lb,la) + 1;
        return std::min(rb,ra) - std::max(lb,la) + 2;
    }
    return std::min(rb, ra)-std::max(lb,la) + 2;
}


int main()
{
    int nb_loops;
    int la, ra, lb, rb;
    std::vector<std::vector<int>> v;
    std::vector<int> inpt_v;
    std::vector<int> res;
    std::cin>>nb_loops;

    for(int i=0; i<nb_loops; i++)
    {
        std::cin>>la>>ra;
        std::cin>>lb>>rb;
        inpt_v.push_back(la);
        inpt_v.push_back(ra);
        inpt_v.push_back(lb);
        inpt_v.push_back(rb);
        v.push_back(inpt_v);
        inpt_v.clear();
    }
    for (auto i : v){
        res.push_back(gwd_process(i[0], i[1], i[2], i[3])); 
    }
    for (auto i : res){
        std::cout<<i<<"\n";
    }
    return 0;
}