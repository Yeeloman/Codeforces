#include <iostream>
#include <vector>


using d_matrix = std::vector<std::vector<int>>; 


void defeat_dragons(d_matrix &dragons, int s){
    int sf = s;
    for(auto i : dragons){
        if(sf <= i[0]){
            std::cout<<"NO"<<'\n'; 
            return;
        }   
        sf += i[1]; 
    }

    std::cout<<"YES"<<'\n';
}


void merge(d_matrix &matrix, d_matrix &left, d_matrix &right)
{
    int i = 0, j = 0, k = 0;

    while(i < left.size() && j < right.size()){
        if(left[i][0]<right[j][0])matrix[k++]=left[i++];
        else matrix[k++]=right[j++];
    }

    while(i < left.size()) matrix[k++]=left[i++];
    while(j < right.size()) matrix[k++]=right[j++];
}

void merge_sort(d_matrix &matrix)
{
    int len = matrix.size();
    if (len <= 1) return;

    int middle = len / 2;
    d_matrix left(matrix.begin(), matrix.begin()+middle); 
    d_matrix right(matrix.begin()+middle , matrix.end());
    merge_sort(left);
    merge_sort(right);

    merge(matrix, left, right);
}


int main()
{
    std::vector<std::vector<int>> dragons;
    int s, loop, hp, exp;
    std::cin>>s>>loop;

    for(int i=0; i < loop; i++) 
    {
        std::cin>>hp>>exp; 
        dragons.push_back({hp, exp}); 
    }

    merge_sort(dragons);
    defeat_dragons(dragons, s);
    
    return 0;
}