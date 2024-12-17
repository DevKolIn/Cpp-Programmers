#include <cmath>

using namespace std;

int GetCountDivisors(int num)
{
    int count = 0;
    int numSquare = sqrt(num);
    
    for (int divisor = 1; divisor <= numSquare; divisor++)
    {
        if (num % divisor == 0)
        {
            int quotient = num / divisor;
            if (divisor != quotient)
            {
                count += 1;
            }
            
            count += 1;
        }
    }

    return count;
}

int solution(int left, int right) {
    int result = 0;
    
    for (int num = left; num <= right; num++)
    {
        int count = GetCountDivisors(num);
        if (count % 2 == 0)
            result += num;
        else
            result -= num;
    }
    
    return result;
}