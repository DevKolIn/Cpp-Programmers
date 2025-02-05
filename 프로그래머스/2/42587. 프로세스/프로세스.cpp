#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int order = 0;

    while (!q.empty()) {
        int priority = q.front().first;
        int index = q.front().second;
        q.pop();

        if (priority < pq.top()) {
            q.push({priority, index});
        } else {
            pq.pop();
            order++;

            if (index == location) return order;
        }
    }

    return -1;
}