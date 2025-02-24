#include <string>
#include <vector>

using namespace std;

int GetOtherBitCount(int num, int num2)
{
    int count = 0;
    
    num2 = num ^ num2;
    while (num2)
    {
        if (num2 & 1)
            count++;
        num2 = num2 >> 1;
    }
    
    return count;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long x : numbers)
    {
        if (x % 2 == 0)
        {
            answer.push_back(x + 1);
        }
        else
        {   
            long long next_num = x + 1;
            long long diff = ((x ^ next_num) >> 2);
            
            answer.push_back(next_num + diff);
        }
    }
    return answer;
}