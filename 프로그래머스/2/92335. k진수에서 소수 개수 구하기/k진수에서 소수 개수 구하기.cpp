#include <cmath>

bool isPrimeNum(long long num)
{
    if (num <= 1)
        return false;
    
    int sqrtNum = std::sqrt(num);
    for (int i = 2; i <= sqrtNum; ++i)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0, remain = 0;
    long long num = 0;
    
    while (n)
    {
        remain = n % k;
        
        if (remain == 0)
        {
            if (isPrimeNum(num))
            {
                answer++;
            }
            
            num = 0;
        }
        else
        {
            int digits = (num == 0) ? 0 : log10(num) + 1;
            num = remain * pow(10, digits) + num;
        }
        
        n = n / k;
    }
    
    if (isPrimeNum(num))
    {
        answer++;
    }

    return answer;
}