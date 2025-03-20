#include <iostream>
#include <vector>


int FindPositionXY(int x, int y, int n)
{
    int distance = 0; 
    for(int i = 1; i<=n/2; i++)   
    {
        if((x==i || x==n+1-i) && (y >= i && y <= n+1-i)) return distance;
        if((y==i || y==n+1-i) && (x >= i && x <= n+1-i)) return distance;
        distance++;
    }
    return distance;
}

int GetOutput(int n, int xo, int yo, int xt, int yt)
{
    int dstc_one = FindPositionXY(xo, yo, n); 
    int dstc_two = FindPositionXY(xt, yt, n); 

    int res = abs(dstc_one - dstc_two);
    return res;
}



int main()
{
    std::vector<int> results;
    int steps = 0; 
    int t, n, xo, yo, xt, yt;
    int outp;
    std::cin>>t;

    for(int i = 0; i < t; i++)
    {
        std::cin>>n>>xo>>yo>>xt>>yt;
        outp = GetOutput(n, xo, yo, xt, yt);
        results.push_back(outp);
    }
    
    for(auto i : results)
    {
        std::cout<<i<<"\n";
    }
    return 0;
}