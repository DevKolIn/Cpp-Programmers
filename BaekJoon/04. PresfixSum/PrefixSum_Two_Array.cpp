#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> arr = {
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10},
    };
    
    int rows = arr.size();
    int cols = arr[0].size();

    std::vector<std::vector<int>> prefixSum(rows + 1, std::vector<int>(cols + 1, 0));

    for (int y = 1; y <= rows; ++y)
    {
        for (int x = 1; x <= cols; ++x)
        {
            prefixSum[y][x] = prefixSum[y - 1][x] 
                              + prefixSum[y][x - 1]
                              - prefixSum[y - 1][x - 1]
                              + arr[y - 1][x - 1];
        }
    }

    for (const auto& row : prefixSum) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}