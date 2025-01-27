#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerines) {
    map<int, int> map;
    
    for (int tangerine : tangerines)
    {
        map[tangerine]++;
    }
    
    vector<pair<int, int>> vec(map.begin(), map.end());
    
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });
    
    int sum = 0;
    int answer = 0;
    for (const auto& pair : vec)
    {
        sum += pair.second;
        answer++;
        
        if (sum >= k)
            break;
    }
    
    return answer;
}