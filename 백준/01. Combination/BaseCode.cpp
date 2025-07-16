#include <iostream>
#include <vector>

std::vector<int> arr;
std::vector<int> current;

void Combination(int index, int r)
{
    if (current.size() == r)
    {
        for (int num : current)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        current.push_back(arr[i]);
        Combination(i + 1, r);
        current.pop_back();
    }
}

int main()
{
    arr = {1,2,3};
    int r = 2;

    current.clear();
    
    Combination(0, 2);
}
