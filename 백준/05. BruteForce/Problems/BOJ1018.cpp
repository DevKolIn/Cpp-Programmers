#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

const int BOARD_SIZE = 8;

int M,N;
std::vector<std::vector<char>> arr;

enum BoardColor
{
    BLACK = 0,
    WHITE,
    COUNT
};

struct Pos
{
    int y;
    int x;

    Pos() {}
    Pos(int y, int x) : y(y), x(x) {}
};

int getMinChessBoardRepaints(const Pos& startPos)
{
    int missCounts[BoardColor::COUNT] = {0, 0};

    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {  
            Pos currentPos = {startPos.y + y, startPos.x + x};
            char currentBoardColor = arr[currentPos.y][currentPos.x];

            char WhiteBoardColor = ((y + x) % 2 == 0) ? 'W' : 'B';
            char BlackBoardColor = ((y + x) % 2 == 0) ? 'B' : 'W';

            // White 체크
            if (currentBoardColor != WhiteBoardColor)
            {
                missCounts[BoardColor::WHITE]++;
            }

            // Black 체크
            if (currentBoardColor != BlackBoardColor)
            {
                missCounts[BoardColor::BLACK]++;
            }
        }
    }

    return std::min(missCounts[BoardColor::BLACK], missCounts[BoardColor::WHITE]);
}

int main()
{
    std::cin >> M >> N;
    arr = std::vector<std::vector<char>>(M, std::vector<char>(N));

    for (int y = 0; y < M; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            std::cin >> arr[y][x];
        }
    }

    int answer = INT_MAX;
    for (int y = 0; y <= M - BOARD_SIZE; ++y)
    {
        for (int x = 0; x <= N - BOARD_SIZE; ++x)
        {
            Pos StartPos = {y, x};
            answer = std::min(answer, getMinChessBoardRepaints(StartPos));
        }
    }

    std::cout << answer;
}