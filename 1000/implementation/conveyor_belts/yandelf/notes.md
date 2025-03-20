# B. Conveyor Belts Notes


### My solution(main.cpp) : 

so my solution consists of finding the "level" of the starting point, then the level of the position to reach, then i do a substraction and return its absolute value.

here is the most important function

```cpp
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
```

as you can see here what i did is that i started a distance at 0, the distance 0 means that we are checking if our x and y are in our outer level, if not we add 1 to our i, then we check the level under it etc etc.. 

the issue with this method is that it takes O(n) time, so altho it works its too slow for codeforces

### Optimal solution(ancillary.cpp) :

the optimal solution follows the same pattern but uses a different way to calculate the distance, instead of using my method to add, it just takes the minimum of all the distances that a position x y has regarding the outer level, using 

```cpp
std::min({x-1, y-1, n-x, n-y})
```

all of these represents the distance between our point and the outer level, we do that with both our starting point and the point we are trying to reach, we computer the absolute value of the difference and we return it