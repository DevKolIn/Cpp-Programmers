#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <iostream>

using namespace std;

bool isPrimNum(string& str)
{
    if (str.empty())
        return false;
    
    long num = std::stol(str);
    if (num < 2)
        return false;
    
    long numSqrt = sqrt(num);
    for (int i = 2; i <= numSqrt; i++)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    deque<char> dq;
    
    while (n)
    {
        int remainder = n % k;
        if (remainder == 0)
        {
            if (dq.size() != 0)
            {
                string str = string(dq.begin(), dq.end());
                if (isPrimNum(str))
                {
                    answer++;
                }
            }
            
            dq.clear();
        }
        else
        {
            dq.push_front(remainder + '0');
        }
        
        n = n / k;
    }
    
    string str = string(dq.begin(), dq.end());
    if (isPrimNum(str))
    {
        answer++;
    }
        
    return answer;
}