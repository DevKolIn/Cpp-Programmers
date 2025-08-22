#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

struct Vertex
{
    vector<int> out;
    vector<int> in;
};

vector<int> solution(vector<vector<int>> edges) {
    unordered_map<int, Vertex> m;

    for (vector<int>& edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        m[from].out.push_back(to);
        m[to].in.push_back(from);
    }

    vector<int> ans(4, 0);
    for (auto &[num, v] : m)
    {
        if (v.out.size() >= 2 && v.in.empty())
            ans[0] = num;
    }
    
    auto count_VE = [&](int start) -> pair<int, int> {
        unordered_set<int> vis;
        vis.reserve(1024);
        
        int V = 0, E = 0;
        stack<int> st;
        st.push(start);
        
        while (!st.empty())
        {
            int num = st.top();
            st.pop();
            
            if (vis.insert(num).second == false)
                continue;
            
            V += 1;
            E += m[num].out.size();
            for (int num : m[num].out)
            {
                if (vis.count(num) == false)
                    st.push(num);
            }
        }
        
        return {V, E};
    };

    Vertex& addV = m[ans[0]];
    for (int num : addV.out)
    {
        auto [V, E] = count_VE(num);

        if (V == E)     ans[1]++;
        if (V == E + 1) ans[2]++;
        if (V == E - 1) ans[3]++;
    }

    return ans;
}