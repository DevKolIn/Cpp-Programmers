#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> scores) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int minLoop = min(static_cast<int>(scores.size()), k);
    for (int i = 0; i < minLoop; i++)
    {
        pq.push(scores[i]);
        answer.push_back(pq.top());
    }
    
    for (int i = k; i < scores.size(); i++)
    {
        pq.push(scores[i]);
        pq.pop();
        answer.push_back(pq.top());
    }
        
    return answer;
}