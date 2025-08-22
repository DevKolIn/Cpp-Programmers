#include <vector>
#include <algorithm>

using namespace std;

bool isParallel(vector<vector<int>>& lineA, vector<vector<int>>& lineB)
{
    int v1x = lineA[1][0] - lineA[0][0];
    int v1y = lineA[1][1] - lineA[0][1];
    int v2x = lineB[1][0] - lineB[0][0];
    int v2y = lineB[1][1] - lineB[0][1];
    
    return (v1x * v2y - v1y * v2x) == 0;
}

int solution(vector<vector<int>> dots) {
    vector<int> arr = {0, 1, 2, 3};
    vector<int> mask = {0, 0, 1, 1};
    
    do {
        vector<vector<int>> lineA, lineB;
        
        for (int i = 0; i < arr.size(); i++)
        {
            if (mask[i])
                lineA.push_back(dots[arr[i]]);
            else
                lineB.push_back(dots[arr[i]]);
        }
        
        if (isParallel(lineA, lineB))
            return 1;
        
    } while (next_permutation(mask.begin(), mask.end()));

    
    return 0;
}