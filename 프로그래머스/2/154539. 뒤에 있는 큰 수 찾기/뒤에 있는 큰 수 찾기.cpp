#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int numSize = numbers.size();
    vector<int> answer(numSize, -1);
    stack<int> stack;
    
    for (int idx = numSize - 1; idx >= 0; --idx)
    {
        while (!stack.empty() && numbers[idx] >= stack.top())
        {
            stack.pop();
        }
        
        if (!stack.empty())
        {
            answer[idx] = stack.top();
        }
        
        stack.push(numbers[idx]);
    }
    
    return answer;
}