#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

std::vector<std::string> splitBySpace(const std::string& str) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int TimeToInt(const string& time)
{
    std::stringstream ss(time);
    std::string strHour, strMinute;
    
    std::getline(ss, strHour, ':');
    std::getline(ss, strMinute, ':');

    int hour = stoi(strHour);
    int minute = stoi(strMinute);
    
    return (hour * 60) + minute;
}

const int MAX_DAY_MINUTE = 1439;

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<string, int> dataMap;
    map<string, int> sumMap;
    
    for (string& record : records)
    {
        std::vector<std::string> result = splitBySpace(record);
        string& strTime = result[0];
        string& strCarNum = result[1];
        string& strCarInOut = result[2];
        
        auto it = dataMap.find(strCarNum);
        if (it != dataMap.end())
        {
            sumMap[strCarNum] += TimeToInt(strTime) - it->second;
            dataMap.erase(it);
        }
        else
        {
            dataMap[strCarNum] = TimeToInt(strTime);
        }
    }
    
    for (auto& pair : dataMap)
    {
        sumMap[pair.first] += MAX_DAY_MINUTE - pair.second;
    }
    
    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    vector<int> answer;
    for (auto& pair : sumMap)
    {
        int fee = defaultFee;
        int sumTime = pair.second;
        
        if (sumTime >= defaultTime)
        {
            int totalTime = ceil(((float)sumTime - defaultTime) / unitTime);
            fee = defaultFee + totalTime * unitFee;
        }

        answer.push_back(fee);
    }
    
    return answer;
}