// https://www.acmicpc.net/problem/11650

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

struct Pos
{
    int x;
    int y;

    bool operator<(const Pos& other) const
    {
        if (x != other.x)
            return x < other.x;

        return y < other.y;
    }
};

int main()
{
    int N;
    std::cin >> N;

    std::string bufferflush;
    std::getline(std::cin, bufferflush);
 
    std::vector<Pos> posArr(N);
    for (int i = 0; i < N; ++i)
    {
        std::string inputStr;
        std::getline(std::cin, inputStr);

        std::istringstream iss(inputStr);
        {
            iss >> posArr[i].x;
            iss >> posArr[i].y; 
        }
    }

    std::sort(posArr.begin(), posArr.end());

    for (const Pos& pos : posArr)
    {
        std::cout << pos.x << " " << pos.y;
        std::cout << '\n';
    }
}