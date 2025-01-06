#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int k, int m, vector<int> scores) {
    int answer = 0;
    priority_queue<int> pq;
    
    for (int score :scores)
    {
        pq.push(score);
    }
    
    while (pq.size() >= m)
    {
        int minScore = 9;
        for (int i = 0; i < m; i++)
        {
            minScore = min(minScore, pq.top());
            pq.pop();
        }
        answer += minScore * m;
    }
    
    return answer;
}