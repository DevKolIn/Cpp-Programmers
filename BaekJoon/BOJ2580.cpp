#include <iostream>
#include <vector>

#define SUDOKU_SIZE 9

struct Pos
{
    int y;
    int x;

    Pos() {}
    Pos(int y, int x) : y(y), x(x) {}
};

std::vector<Pos> zeroPositions;
std::vector<std::vector<int>> sudoku(SUDOKU_SIZE, std::vector<int>(SUDOKU_SIZE));
bool isSudokuSolved = false;


void solveSudoku(Pos zeroPos)
{       
    std::vector<bool> isExists(SUDOKU_SIZE, false);

    int index = 0;
    for (int x = 0; x < SUDOKU_SIZE; ++x)
    {
        int num = sudoku[zeroPos.y][x];
        if (num == 0)
            continue;

        index = num - 1;
        isExists[index] = true;
    }

    for (int y = 0; y < SUDOKU_SIZE; ++y)
    {
        int num = sudoku[y][zeroPos.x];
        if (num == 0)
            continue;

        index = num - 1;
        isExists[index] = true;
    }


    for (int y = 0; y < 3; ++y)
    {
       for (int x = 0; x < 3; ++x)
       {
            Pos squarePos;
            squarePos.y = zeroPos.y - (zeroPos.y % 3) + y;
            squarePos.x = zeroPos.x - (zeroPos.x % 3) + x;
            int num = sudoku[squarePos.y][squarePos.x];
            if (num == 0)
                continue;

            index = num - 1;
            isExists[index] = true;
       } 
    }

    std::vector<int> possibleNums;
    for (int i = 0; i < SUDOKU_SIZE; ++i)
    {
        if (isExists[i] == false)
            possibleNums.push_back(i + 1);
    }

    if (possibleNums.size() == 1 && zeroPositions.empty())
    {
        isSudokuSolved = true;
        sudoku[zeroPos.y][zeroPos.x] = possibleNums[0];
        return;
    }

    for (int i = 0; i < possibleNums.size(); ++i)
    {
        sudoku[zeroPos.y][zeroPos.x] = possibleNums[i];
        Pos nextZeroPos = zeroPositions.back();
        zeroPositions.pop_back();
        solveSudoku(nextZeroPos);
        
        if (isSudokuSolved)
            break;
        
        sudoku[zeroPos.y][zeroPos.x] = 0;
        zeroPositions.push_back(nextZeroPos);
    }
}

int main()
{
    for (int y = 0; y < SUDOKU_SIZE; ++y)
    {
        for (int x = 0; x < SUDOKU_SIZE; ++x)
        {
            std::cin >> sudoku[y][x];

            if (sudoku[y][x] == 0)
            {
                zeroPositions.push_back(Pos(y,x));
            }
        }
    }

    Pos zeroPos = zeroPositions.back();
    zeroPositions.pop_back();
    solveSudoku(zeroPos);

    for (int y = 0; y < SUDOKU_SIZE; ++y)
    {
        for (int x = 0; x < SUDOKU_SIZE; ++x)
        {
            std::cout << sudoku[y][x] << " ";
        }
        std::cout << '\n';
    }
}