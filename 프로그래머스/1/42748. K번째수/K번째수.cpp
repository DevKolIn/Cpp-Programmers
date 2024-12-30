#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int>& command : commands)
    {
        int startIdx = command[0];
        int endIdx = command[1];
        int nIdx = command[2];
        
        vector<int> sliceV(array.begin() + startIdx - 1, array.begin() + endIdx);
        sort(sliceV.begin(), sliceV.end());
        answer.push_back(sliceV[nIdx - 1]);
    }
    
    return answer;
}