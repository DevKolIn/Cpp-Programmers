#include <string>
#include <vector>
#include <deque>
#include <map>
#include <stack>

using namespace std;

map<char,char> parenthesesMap =
{
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
};

bool isValid(const deque<char>& dq)
{
    stack<char> stack;
    
    for (auto it = dq.begin(); it < dq.end(); ++it)
    {
        char ch = *it;
        if (stack.size() < 1)
        {
            stack.push(ch);
            continue;
        }

        char top = stack.top();
        if (parenthesesMap.count(top) > 0 && parenthesesMap[top] == ch)
        {
            stack.pop();
        }
        else
        {
            stack.push(ch);
        }
    }
    
    return stack.size() == 0;
}

int solution(string s) {
    int answer = 0;
    
    deque<char> dq;
    for (char ch : s)
    {
        dq.push_back(ch);
    }
    
    for (int i = 0; i < dq.size(); ++i)
    {
        if (isValid(dq))
        {
            answer++;
        }
        
        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    
    return answer;
}