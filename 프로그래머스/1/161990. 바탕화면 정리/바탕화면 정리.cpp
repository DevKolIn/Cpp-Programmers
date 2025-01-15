#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {50,50,0,0};

    const int height = wallpaper.size();
    const int width = wallpaper[0].size();
    
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (wallpaper[y][x] == '#')
            {
                answer[0] = min(answer[0], y);
                answer[1] = min(answer[1], x);
                answer[2] = max(answer[2], y + 1);
                answer[3] = max(answer[3], x + 1);
            }
        }    
    }

    return answer;
}