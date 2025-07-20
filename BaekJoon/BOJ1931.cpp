#include <iostream>
#include <vector>
#include <algorithm>

struct Pos
{
    bool operator<(const Pos& other) const
    {
        if (end != other.end)
            return end < other.end;
        
        return start < other.start;
    }

    int start;
    int end;
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<Pos> arr(N); 
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i].start >> arr[i].end;
    }

    std::sort(arr.begin(), arr.end());

    int end = 0, answer = 0;
    for (Pos& currPos : arr)
    {
        if (currPos.start < end)
            continue;

        end = currPos.end;
        answer++;
    }

    std::cout << answer;
}