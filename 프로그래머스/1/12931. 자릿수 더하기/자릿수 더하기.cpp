#include <iostream>

using namespace std;
int solution(int n)
{
    int sum = 0;
    
    while (n > 0)
    {
        int remain = n % 10;
        sum += remain;
        n /= 10;
    }

    return sum;
}