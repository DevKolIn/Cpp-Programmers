#include <queue>
#include <unordered_set>
using namespace std;

int bfs(int x, int y, int n)
{
    if (x == y)
        return 0; 

    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        // 다음 가능한 연산들
        int next_values[] = {current + n, current * 2, current * 3};

        for (int next : next_values) {
            if (next == y)
                return steps + 1;

            if (next < y && visited.find(next) == visited.end()) {
                q.push({next, steps + 1});
                visited.insert(next);
            }
        }
    }

    return -1; 
}

int solution(int x, int y, int n) {
    return bfs(x,y,n);
}