#include <deque>
#include <vector>
#include <iostream>

using namespace std;
deque<pair<int, int>> bridge;
int curBridgeWeight = 0;
int truckIdx = 0;

void EnterTruck(int curTime, int truckWeight)
{
    bridge.push_back({curTime, truckWeight});
    curBridgeWeight += truckWeight;
    truckIdx++;
}

void ExitTruck()
{
    auto frontTruck = bridge.front();
    curBridgeWeight -= frontTruck.second;
    bridge.pop_front();
}

bool CanEnterBridge(vector<int>& truck_weights, int limitedWeight)
{
    if (truckIdx >= truck_weights.size())
        return false;
    
    return (curBridgeWeight + truck_weights[truckIdx]) <= limitedWeight;
}

bool ShouldExitBridge(int curTime, int bridge_length)
{
    pair<int, int> frontTruck = bridge.front();
    return bridge_length <= (curTime - frontTruck.first);
}

int solution(int bridge_length, int limitedWeight, vector<int> truck_weights) {
    int time = 0;
    EnterTruck(time, truck_weights[truckIdx]);
    while (!bridge.empty())
    { 
        if (ShouldExitBridge(time, bridge_length))
        {
            ExitTruck();
        }
        
        if (CanEnterBridge(truck_weights, limitedWeight))
        {
            EnterTruck(time, truck_weights[truckIdx]);
        }
        
        ++time;
    }
    
    return time;
}