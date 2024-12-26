#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int result = 0;
    int size = number.size();
    
    for (int a = 0; a < size; a++)
    {
        for (int b = a + 1; b < size; b++)
        {
            for (int c = b + 1; c < size; c++)
            {
                int sum = number[a] + number[b] + number[c];
                if (sum == 0)
                    result++;
            }
        }
    }
    
    return result;
}