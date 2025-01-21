#include <string>
#include <sstream>
#include <istream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void split(char delimiter, const string& str, string& left, string& right)
{
    std::istringstream stream(str);
    string token;
    
    getline(stream, token, delimiter);
    left = token;
    
    getline(stream, token, delimiter);
    right = token;
}

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, int> UserReportCounts;
    unordered_map<string, set<string>> ReportedUsers;
    unordered_map<string, int> UserIndex;
    
    for (int index = 0; index < id_list.size(); ++index)
    {
        UserIndex[id_list[index]] = index;
    }
    
    for (const string& report : reports)
    {
        string userId;
        string target;
        split(' ', report, userId, target);
        
        if (ReportedUsers[target].find(userId) == ReportedUsers[target].end())
        {
            UserReportCounts[target]++;
            ReportedUsers[target].insert(userId);
        }
    }
    
    for (const string& userId : id_list)
    {
        int ReportCount = UserReportCounts[userId];
        
        if (ReportCount >= k)
        {
            for (const string& user : ReportedUsers[userId])
            {
                int userIndex = UserIndex[user];
                answer[userIndex]++;
            }
        }
    }
    
    return answer;
}