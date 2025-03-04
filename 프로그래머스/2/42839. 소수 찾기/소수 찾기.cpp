#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

bool isPrimeNum(int num)
{
    if (num < 2)
        return false;
    
    int numSqrt = sqrt(num);
    
    for (int i = 2; i <= numSqrt; ++i)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    unordered_set<int> set;
    
    sort(numbers.begin(), numbers.end());
        
    do
    {
        int num = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            num *= 10;
            num += numbers[i] - '0';
            
            if (set.count(num) == 0 && isPrimeNum(num))
            {
                ++answer;
                set.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}