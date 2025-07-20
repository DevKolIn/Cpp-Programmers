#include <iostream>
#include <vector>

std::vector<int> arr = {500, 100, 50, 10, 5, 1};

int main()
{
    int pay;
    std::cin >> pay;

    int money = 1000 - pay;

    int answer = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        while (money >= arr[i])
        {
            money -= arr[i];
            answer++;
        }
    }

    std::cout << answer;
}