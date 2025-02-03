#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> numbers, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> map;
    int totalNumber = accumulate(numbers.begin(), numbers.end(), 0);
    
    for (int i = 0; i < totalNumber; ++i)
    {
        map[discount[i]]++;
    }
    
    for (int i = 0; i < discount.size() - totalNumber + 1; ++i)
    {
        bool achieve = true;
        
        for (int j = 0; j < want.size(); ++j)
        {
            string fruit = want[j];
            int number = numbers[j];
            if (map[fruit] < number)
            {
                achieve = false;
                break;     
            }
        }

        
        if (achieve == true)
        {
            answer++;
        }
        if (i + 1 + totalNumber < discount.size())
        {
            map[discount[i]]--;
            map[discount[i + totalNumber]]++;
        }
    }
    
    return answer;
}