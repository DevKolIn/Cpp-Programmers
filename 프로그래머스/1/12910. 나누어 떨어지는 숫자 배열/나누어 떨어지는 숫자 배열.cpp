#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int num : arr)
    {
        if (num % divisor == 0)
            pq.push(num);
    }
    
    if (pq.size())
    {
        while (!pq.empty())
        {
            int num = pq.top();
            pq.pop();
            result.push_back(num);
        }
    }
    else
    {
        result.push_back(-1);
    }
    
    return result;
}