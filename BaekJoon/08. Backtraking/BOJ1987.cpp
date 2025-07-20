#include <iostream>
#include <vector>

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int R,C;
int answer;

std::vector<std::vector<char>> arr;
std::vector<bool> visited(26, false);

void search(int y, int x, int depth)
{
    if (y < 0 || y >= R || x < 0 || x >= C)
        return;

    char currChar = arr[y][x];
    int index = currChar - 'A';
    if (visited[index])
        return;
    
    depth += 1;
    answer = std::max(answer, depth);
    visited[index] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        search(ny, nx, depth);
    }
    visited[index] = false;
}

int main()
{
    std::cin >> R >> C;

    arr = std::vector<std::vector<char>>(R, std::vector<char>(C));
    for (int y = 0; y < R; ++y)
    {
        for (int x = 0; x < C; ++x)
        {
            std::cin >> arr[y][x];
        }    
    }


    search(0, 0, 0);

    std::cout << answer;
}