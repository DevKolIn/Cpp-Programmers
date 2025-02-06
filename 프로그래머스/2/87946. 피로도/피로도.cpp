#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool ascendingSort(vector<int>& a, vector<int>& b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end(), ascendingSort);
    
    do
    {
        
        int playerFatigue = k;
        int inCount = 0;
        for (vector<int>& dungeon : dungeons)
        {
            int dungeonRequiredFatigue = dungeon[0];
            int dungeonFatigue = dungeon[1];

            if (playerFatigue >= dungeonRequiredFatigue)
            {
                inCount++;
                playerFatigue -= dungeonFatigue;
            }
            else
            {
                break;
            }
        }
        cout << endl;
        answer = max(answer, inCount);
    } while (next_permutation(dungeons.begin(), dungeons.end(), ascendingSort));
    
    return answer;
}