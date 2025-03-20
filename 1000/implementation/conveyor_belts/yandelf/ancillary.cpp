#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>

int GetPosition(int x, int y, int n)
{
    return std::min<int>({x-1, y-1, n-x, n-y}); 
}

int GetResult(int n, int xo, int yo, int xt, int yt)
{
    int distance_start = GetPosition(xo, yo, n);
    int distance_goal= GetPosition(xt, yt, n);
    return std::abs(distance_goal - distance_start);
}

int main()
{
    int t, n, xo, yo, xt, yt, result;
    std::vector<int> results;

    std::cin>>t;

    for(int i = 0; i < t; i++)
    {
        std::cin>>n>>xo>>yo>>xt>>yt;
        result = GetResult(n, xo, yo, xt, yt);
        results.push_back(result);
    }

    for(auto i : results)
    {
        std::cout<<i<<"\n";
    }
    return 0;
}