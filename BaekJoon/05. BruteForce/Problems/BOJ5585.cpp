#include <iostream>
#include <algorithm>
#include <climits>

int answer = INT_MAX;

int main()
{
    int pay;
    std::cin >> pay;

    int money = 1000 - pay;
    
    for (int c_500 = 0; c_500 <= 2; ++c_500)
    {
        for (int c_100 = 0; c_100 <= 10; ++c_100)
        {
            for (int c_50 = 0; c_50 <= 20; ++c_50)
            {
                for (int c_10 = 0; c_10 <= 100; ++c_10)
                {
                    for (int c_5 = 0; c_5 <= 200; ++c_5)
                    {
                        int total = (500 * c_500) + (100 * c_100) + (50 * c_50) + (10 * c_10) + (5 * c_5);
                        if (money >= total)
                        {
                            int c_1 = money - total;
                            answer = std::min(answer, c_500 + c_100 + c_50 + c_10 + c_5 + c_1);
                        }   
                    }
                }
            }
        }
    }

    std::cout << answer;
}