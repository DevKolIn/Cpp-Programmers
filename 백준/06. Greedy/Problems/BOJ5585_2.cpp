#include <iostream>
#include <vector>

int answer;
std::vector<int> arr = {500, 100, 50, 10, 5, 1};

int main()
{
    int pay;
    std::cin >> pay;

    int money = 1000 - pay;
   
    for (int i = 0; i < arr.size(); ++i)
    {
        answer += money / arr[i];
        money %= arr[i];
    }

    std::cout << answer;
}