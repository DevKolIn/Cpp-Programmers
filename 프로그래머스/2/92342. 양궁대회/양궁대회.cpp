#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N = 11;
int R;
int bestPoint;
vector<int> info;
vector<int> bestResult;
vector<int> selectedNums;

int getPoint(vector<int>& apeach, vector<int>& lion)
{
    int apeachPoint = 0;
    int lionPoint = 0;
    
    for (int i = 0; i < 11; ++i)
    {
        if (apeach[i] == 0 && lion[i] == 0)
            continue;
        if (apeach[i] >= lion[i])
            apeachPoint += 10 - i;
        else
            lionPoint += 10 - i;
    }
    
    return lionPoint - apeachPoint;
}

void combination(int start)
{
    if (selectedNums.size() == R)
    {
        vector<int> curResult(N, 0);
        for (int i = 0; i < R; ++i)
            curResult[selectedNums[i] - 1]++;

        int curPoint = getPoint(info, curResult);
        if (curPoint > bestPoint || (curPoint == bestPoint && lexicographical_compare(bestResult.rbegin(), bestResult.rend(), curResult.rbegin(), curResult.rend())))
        {
            bestPoint = curPoint;
            bestResult = curResult;
        }

        return;
    }

    for (int i = start; i <= N; ++i)
    {
        selectedNums.push_back(i);
        combination(i);
        selectedNums.pop_back();
    }
}

vector<int> solution(int n, vector<int> inInfo)
{
    R = n;
    info = inInfo;
    
    combination(1);
    
    if (bestPoint == 0)
        return vector<int>(1, -1);
    
    return bestResult;
}