#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    if (progresses.size() == 1)
        return vector<int>(1,1);
    
    int count = 1;
    int maxDaysLeft = ceil((100.f - progresses[0]) / speeds[0]);
    for (int i = 1; i < progresses.size(); ++i)
    {
        int progress = progresses[i];
        int speed = speeds[i];
        int daysLeft = ceil((100.f - progress) / speed);

        if (daysLeft > maxDaysLeft)
        {
            answer.push_back(count);
            count = 1;
            maxDaysLeft = daysLeft;
        }
        else
        {
            count++;
        }
    }
    
    answer.push_back(count);
    
    return answer;
}