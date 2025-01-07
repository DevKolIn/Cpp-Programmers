#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNum(int num)
{
    int sqrtNum = static_cast<int>(sqrt(num));
    for (int i = 2; i <= sqrtNum; i++)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int z = j + 1; z < size; z++)
            {
                int sum = nums[i] + nums[j] + nums[z];
                 if (isPrimeNum(sum))
                    answer++;
            }
        }
       
    }
    
    return answer;
}