#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int idx, int target)
{
    if (idx >= numbers.size())
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }

    int positiveNum = target + numbers[idx];
    int negativeNum = target - numbers[idx];
    
    return dfs(numbers, idx + 1, positiveNum) + dfs(numbers, idx + 1, negativeNum);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(numbers, 0, target);
    return answer;
}