#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int primeSize = sizeof(primes) / sizeof(primes[0]);

unordered_map<int, int> GetPrimeNumCounts(int num)
{
    unordered_map<int, int> map;
    
    while (num != 1)
    {
        for (int i = 0; i < primeSize; ++i)
        {
            if (num % primes[i] == 0)
            {
                map[primes[i]]++;
                num /= primes[i];
            }
        }
    }
    
    return map;
}

int solution(vector<int> arr) {
    unordered_map<int, int> lcmPrimeNumCounts;
    
    for (int num : arr)
    {
       unordered_map<int, int> PrimeNumCounts = GetPrimeNumCounts(num);
       for (auto& pair : PrimeNumCounts)
       {
           if (lcmPrimeNumCounts[pair.first] < pair.second)
           {
               lcmPrimeNumCounts[pair.first] = pair.second;
           }
       }
    }
    
    int answer = 1;
    for (auto& pair : lcmPrimeNumCounts)
    {
        answer *= pow(pair.first, pair.second);
    }    
    
    return answer;
}