#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> maps;

struct Pos{
    Pos(int y, int x, int dist) : y(y), x(x), dist(dist) {}
    int y;
    int x;
    int dist;
};


int dy[4] =
{
    -1,
    0,
    1,
    0
};

int dx[4] =
{
    0,
    1,
    0,
    -1
};

vector<vector<bool>> discovered;

int bfs(int y, int x)
{  
    queue<Pos> q;
    q.push(Pos(y, x, 1));
    
    discovered[y][x] = true;
    
    while (q.empty() == false)
    {
        Pos curPos = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nextY = curPos.y + dy[i];
            int nextX = curPos.x + dx[i];
            
            Pos nextPos(nextY, nextX, curPos.dist + 1);
            
            if (nextPos.y == (n - 1) && nextPos.x == (m - 1))
                return nextPos.dist;
            // 맵 범위를 벗어난 경우
            if (nextPos.y < 0 || nextPos.y >= n || nextPos.x < 0 || nextPos.x >= m)
                continue;
            // 이미 발견한 경우 
            if (discovered[nextPos.y][nextPos.x])
                continue;
            // 벽인 경우
            if (maps[nextPos.y][nextPos.x] == 0)
                continue;

            q.push(nextPos);
            discovered[nextPos.y][nextPos.x] = true;
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> inputMaps)
{
    maps = inputMaps;
    n = inputMaps.size();
    m = inputMaps[0].size();
    discovered = vector<vector<bool>>(n, vector<bool>(m, false));
    
    return bfs(0,0);
}