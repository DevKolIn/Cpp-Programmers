#include <vector>
#include <iostream>

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,10};
    std::vector<int> prefixSum = {0};

    for (int i = 0; i < arr.size(); ++i)
    {
        int sum = prefixSum[i] + arr[i];
        prefixSum.push_back(sum);
    }

    int a = 1;
    int b = 3;

    int ab_sum = prefixSum[a - 1] + prefixSum[b];
    std::cout << ab_sum;
}