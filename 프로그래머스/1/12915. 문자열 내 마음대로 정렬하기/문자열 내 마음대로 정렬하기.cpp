#include <string>
#include <vector>
#include <queue>

using namespace std;

const int AlphabetLength = 26;

vector<string> solution(vector<string> strings, int n) {
    vector<string> result;
    vector<priority_queue<string, vector<string>, greater<string>>> v(AlphabetLength);
    
    for (string& str : strings)
    {
        int idx = str[n] - 'a';
        auto& queue = v[idx];
        queue.push(str);
    }
    
    for (auto& pq : v)
    {
        while (!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }
    }
    
    return result;
}