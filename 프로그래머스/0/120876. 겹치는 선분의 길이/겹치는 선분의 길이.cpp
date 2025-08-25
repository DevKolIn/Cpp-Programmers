#include <vector>
#include <map>

using namespace std;


int solution(vector<vector<int>> lines)
{
    map<int, int> m;
    
    for (auto& line : lines)
    {
        if (line[0] == line[1])
            continue;
        m[line[0]] += 1;
        m[line[1]] -= 1;
    }
    
    int ans = 0;
    int cover = 0;
    
    auto it = m.begin();
    auto prev = it++;
    cover += prev->second;

    for (; it != m.end(); ++it)
    {
        int x0 = prev->first;
        int x1 = it->first;
        int len = x1 - x0;
        if (len >= 0 && cover >= 2) ans += len;
        
        cover += it->second;
        prev = it;
    }
    
    return ans;
}