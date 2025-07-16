#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

struct Player
{
    int id = 0;
    int SumScore = 0;
    int MulScore = 1;

    bool operator<(const Player& other) const
    {
        if (MulScore != other.MulScore)
            return MulScore < other.MulScore;

        if (SumScore != other.SumScore)
            return SumScore < other.SumScore;

        return id < other.id;
    }
};

int main()
{
    int N;
    std::cin >> N;

    std::string bufferFlush;
    std::getline(std::cin, bufferFlush);

    std::vector<Player> Players(N);
    for (int i = 0; i < N; ++i)
    {
        std::string inputStr;
        std::getline(std::cin, inputStr);

        std::istringstream iss(inputStr);
        {
            iss >> Players[i].id;

            int score;
            while (iss >> score)
            {
                Players[i].SumScore += score;
                Players[i].MulScore *= score;
            }
        }
    }

    std::sort(Players.begin(), Players.end());

    for (int i = 0; i < 3; ++i)
        std::cout << Players[i].id << " ";
    std::cout << '\n';
}