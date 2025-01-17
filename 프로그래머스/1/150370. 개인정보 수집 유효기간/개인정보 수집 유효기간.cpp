#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> termMap;
    
    int year = stoi(today.substr(0, 5));
    int month = stoi(today.substr(5, 7));
    int day = stoi(today.substr(8, 10));
    
    for (string str : terms)
    {
        string term = str.substr(0,1);
        int period = stoi(str.substr(2));
        termMap.insert({term, period});
    }
    
    for (int idx = 0; idx < privacies.size(); idx++)
    {
        int privacyYear = stoi(privacies[idx].substr(0, 5));
        int privacyMonth = stoi(privacies[idx].substr(5, 7));
        int privacyDay = stoi(privacies[idx].substr(8, 10));
        string term = privacies[idx].substr(11);
        
        int period = termMap[term];
        int ElapsedPeriod = ((year - privacyYear) * 12) - privacyMonth + month;
        
        if (ElapsedPeriod > period)
        {
            answer.push_back(idx + 1);
        }
        else if (ElapsedPeriod == period && day >= privacyDay)
        {
            answer.push_back(idx + 1);
        }
    }
    
    return answer;
}