#include <string>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> solution(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    int y = 0, x = 0, dir = 0;
    for (int num = 1; num <= n * n; ++num)
    {
        ans[y][x] = num;
        vis[y][x] = true;
        
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx])
        {
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        
        y = ny; x = nx;
    }
    
    return ans;
}