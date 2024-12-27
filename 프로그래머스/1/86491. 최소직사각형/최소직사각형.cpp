#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxSize = 0;
    int minSize = 0;
    for (vector<int>& size : sizes)
    {
        for (int i = 0; i < 2; i++)
        {
            if (maxSize < size[0])
            {
                maxSize = size[0];
            }
            
            if (maxSize < size[1])
            {
                maxSize = size[1];
            }
            
            int minNum = min(size[0], size[1]);
            if (minSize < minNum)
            {
                minSize = minNum;
            }
        }
    }
    
    return maxSize * minSize;
}