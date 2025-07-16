#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

int N;
std::vector<std::vector<char>> arr;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int get_maxlength(int starty, int startx)
{
    int result = 1;

    {
        int length = 0;
        char currChar = '-';
        char prevChar = '-';

        int y = starty;
        for (int x = 0; x < N; ++x)
        {
            currChar = arr[y][x];
            
            if (currChar == prevChar)
            {
                length++;
                result = std::max(result, length);
            }
            else
            {
                length = 1;
            }

            prevChar = currChar;
        }
    }
        
    {
        int length = 0;
        char currChar = '-';
        char prevChar = '-';

        int x = startx;
        for (int y = 0; y < N; ++y)
        {
            currChar = arr[y][x];

            if (currChar == prevChar)
            {
                length++;
                result = std::max(result, length);
            }
            else
            {
                length = 1;
            }

            prevChar = currChar;
        }
    }

    return result;
}

int main()
{
    
    std::cin >> N;

    arr = std::vector<std::vector<char>>(N, std::vector<char>(N, 0));

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            std::cin >> arr[y][x];
        }
    }

    int answer = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (y == x)
                answer = std::max(answer, get_maxlength(y, x));
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if ((0 < nx && nx < N) == false ||
                    (0 < ny && ny < N) == false)
                    continue;
                
                if (arr[y][x] == arr[ny][nx])
                    continue;

                std::swap(arr[y][x], arr[ny][nx]);
                answer = std::max(answer, get_maxlength(y, x));
                std::swap(arr[y][x], arr[ny][nx]);
            }
        }
    }

    std::cout << answer;
}