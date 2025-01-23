#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    
    // 블록을 한 줄로 나열했을 때의 길이
    int area = brown + yellow;
    
    // 카펫의 가로는 최소 3부터 시작한다.
    for (int width = 3; width <= area; ++width)
    {
        if (area % width != 0)
            continue;
        
        int height = area / width;

        if ((width - 2) * (height - 2)  == yellow)
        {
            answer[0] = max(width, height);
            answer[1] = min(width, height);
            break;
        }
    }
    
    return answer;
}