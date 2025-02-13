#include <string>
#include <vector>

using namespace std;

double solution(vector<int> nums) {
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }
    
    return static_cast<double>(sum) / nums.size();
}