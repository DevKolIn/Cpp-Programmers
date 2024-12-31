#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    deque<int> dq;
    dq.push_back(0);
    
    for (int i = food.size() - 1; i > 0; i--)
    {
        int shareFoodCount = food[i] / 2;
        while (shareFoodCount)
        {
            dq.push_front(i);
            dq.push_back(i);
            --shareFoodCount;
        }
    }
    
    for (int foodIdx : dq)
    {
        answer += static_cast<char>('0' + foodIdx);
    }
    
    return answer;
}