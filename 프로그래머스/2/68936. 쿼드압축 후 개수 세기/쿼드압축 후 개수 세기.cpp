#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> bits;
vector<int> result;

void searchBit(int startY, int endY, int startX, int endX)
{
    int firstBit = bits[startY][startX];

    bool isUniform = true;
    for (int y = startY; y < endY; ++y)
    {
        for (int x = startX; x < endX; ++x)
        {
            if (bits[y][x] != firstBit)
            {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }

    if (isUniform)
    {
        result[firstBit]++;
        return;
    }

    int midY = (startY + endY) / 2;
    int midX = (startX + endX) / 2;

    searchBit(startY, midY, startX, midX); // 왼쪽 상단
    searchBit(startY, midY, midX, endX);   // 오른쪽 상단
    searchBit(midY, endY, startX, midX);   // 왼쪽 하단
    searchBit(midY, endY, midX, endX);     // 오른쪽 하단
}

vector<int> solution(vector<vector<int>> arr) {
    bits = arr;
    result = vector<int>(2, 0);
    searchBit(0, arr.size(), 0, arr.size());
    return result;
}