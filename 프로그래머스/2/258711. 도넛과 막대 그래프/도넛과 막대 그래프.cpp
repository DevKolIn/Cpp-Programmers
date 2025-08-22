#include <string>
#include <vector>
#include <map>

using namespace std;

struct Vertex
{
    vector<int> outDegree;
    vector<int> inDegree;
};

int vCnt, eCnt;
map<int, Vertex> m;
map<int, bool> visited;

void dfs(int num)
{
    Vertex& v = m[num];
    
    if (visited[num] == false)
    {
        vCnt += 1;
        visited[num] = true;
    }
    
    if (v.outDegree.empty())
        return;
    
    while (v.outDegree.size())
    { 
        int num = v.outDegree.back();
        v.outDegree.pop_back();
        dfs(num);
        eCnt += 1;
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> ans(4, 0);
    
    for (vector<int>& edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        m[from].outDegree.push_back(to);
        m[to].inDegree.push_back(from);
    }
    
    for (auto &element : m)
    {
        int num = element.first;
        Vertex& v = element.second;
        
        if (v.outDegree.size() >= 2 && v.inDegree.size() == 0)
            ans[0] = num;
    }
    
    Vertex& addV = m[ans[0]];
    for (int num : addV.outDegree)
    {
        vCnt = 0, eCnt = 0;
        dfs(num);
        
        if (vCnt == eCnt)     ans[1]++;
        if (vCnt == eCnt + 1) ans[2]++;
        if (vCnt == eCnt - 1) ans[3]++;
    }
    
    return ans;
}