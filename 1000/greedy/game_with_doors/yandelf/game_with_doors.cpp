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
    std::vector<int> res;
    std::cin>>nb_loops;

    for(int i=0; i<nb_loops; i++)
    {
        std::cin>>la>>ra;
        std::cin>>lb>>rb;
        res.push_back(gwd_process(la, ra, lb, rb));
    }
    for (auto i : res){
        std::cout<<i<<"\n";
    }
    return 0;
}