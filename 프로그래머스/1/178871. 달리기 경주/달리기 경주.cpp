#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> map1;

    for (int idx = 0; idx < players.size(); ++idx)
    {
        map1[players[idx]] = idx;
    }
    
    for (string calling : callings)
    {
        int& callingPlayerNum = map1[calling];
        string nextPlayer = players[callingPlayerNum - 1];
        swap(map1[calling], map1[nextPlayer]);
        swap(players[callingPlayerNum + 1], players[callingPlayerNum]);
    }
    
    return players;
}