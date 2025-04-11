#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> orders) {
    int answer = 0;
    
    int maxSize = orders.size();
    stack<int> tempContainer;
    
    int currBoxNum = 1;
    for (int currOrder : orders)
    {
        while (true)
        {
            if (currOrder == currBoxNum)
            {
                answer++;
                currBoxNum++;
                break;
            }
            if (tempContainer.empty() == false 
                && currOrder == tempContainer.top())
            {
                tempContainer.pop();
                answer++;
                break;
            }
            if (currBoxNum > maxSize)
                return answer;
            
            tempContainer.push(currBoxNum);
            currBoxNum++;
        }
    }
    
    return answer;
}