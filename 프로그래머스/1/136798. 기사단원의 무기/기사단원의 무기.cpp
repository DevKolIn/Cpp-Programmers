#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getPrimeNumberCount(int num)
{
    int count = 0;
    int sqrtNum = static_cast<int>(sqrt(num));
    
    if (num == 1)
    {
        return 1;
    }
    
    for (int i = 1; i <= sqrtNum; i++)
    {
        if (num % i == 0)
        {
            if (num / i == i)
            {
                count += 1;
            }
            else
            {
                count += 2;
            }
        }
    }
    
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int num = 1; num <= number; num++)
    {
        int primeNumberCount = getPrimeNumberCount(num);
        if (primeNumberCount > limit)
        {
            answer += power;  
        }
        else
        {
            answer += primeNumberCount;
        }
        
    }
        
    return answer;
}