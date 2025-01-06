#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    int idx;
    int score;
    vector<int> pattern;
};

bool compare(const student& a, const student& b)
{
    if (a.score > b.score)
        return true;
    return false;
}

vector<int> solution(vector<int> answers) {  
    vector<student> students =
    {
        {1, 0, {1, 2, 3, 4, 5}},
        {2, 0, {2, 1, 2, 3, 2, 4, 2, 5}},
        {3, 0, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}}
    };
    
    vector<int> result;
    
    // 더한다.
    for (int j = 0; j < students.size(); j++)
    {
        int size = students[j].pattern.size();
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == students[j].pattern[i % size])
                students[j].score += 1;
        }  
    }
    
    // 내림차순 정렬한다.
    sort(students.begin(), students.end(), compare);
    
    // 소거한다.
    int maxScore = students[0].score;
    result.push_back(students[0].idx);
    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].score < maxScore)
        {
            break;
        }
        
        result.push_back(students[i].idx);
    }
    
    return result;
}