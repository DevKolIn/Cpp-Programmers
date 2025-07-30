#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

#define EndTime 1439

using namespace std;

struct ParkingInfo
{
    int inTime = -1;
    int totalTime = 0;
};

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, ParkingInfo> parkingUsers;
        
    for (const string& record : records)
    {
        istringstream iss(record);
        string time, carNum, inout;
        iss >> time >> carNum >> inout;
        
        istringstream timeIss(time);
        int hour, minute; char colon;
        timeIss >> hour >> colon >> minute;
        
        int timeMinute = hour * 60 + minute;
        
        ParkingInfo& parkinginfo = parkingUsers[carNum];
            
        if (inout == "IN")
        {
            parkinginfo.inTime = timeMinute;
        }
        else
        {
            parkinginfo.totalTime += timeMinute - parkinginfo.inTime;
            parkinginfo.inTime = -1;
        }
    }
    
    vector<int> ret;
    for (auto& parkingUser : parkingUsers)
    {
        ParkingInfo& parkingInfo = parkingUser.second;
        
        if (parkingInfo.inTime != -1)
        {
            parkingInfo.totalTime += EndTime - parkingInfo.inTime;
        }
        
        int fee = fees[1];
        
        if (parkingInfo.totalTime > fees[0])
        {
            int unitTime = ceil(((parkingInfo.totalTime - fees[0]) / (float)fees[2]));
            fee += unitTime * fees[3];
        }
        
        ret.push_back(fee);
    }
    
    return ret;
}