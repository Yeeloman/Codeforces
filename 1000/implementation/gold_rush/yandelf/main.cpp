#include <iostream>
#include <string>
#include <vector>


std::string rush_gold(int n, int m) {
    int right_n, left_n;
    std::string right_s, left_s;

    if(n == m) return "YES";
    if(n % 3 != 0) return "NO";

    right_n = n * 2 / 3;
    left_n = n / 3;

    right_s = rush_gold(right_n, m);
    left_s = rush_gold(left_n, m);

    if(right_s == "YES" || left_s == "YES") return "YES";

    return "NO";
}

int main() {
    int n, m;
    std::vector<std::string> res;
    int t; 
    std::cin>>t;

    for(int i = 0; i < t ; i++){
        std::cin>>n>>m;
        res.push_back(rush_gold(n, m));
    } 

    for(auto i : res){
        std::cout<<i<<std::endl;
    }
    return 0;
}