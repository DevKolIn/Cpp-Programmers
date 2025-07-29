#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Enroll
{
    string referral;
    int amount;
    
    Enroll() {}
    Enroll(int amount) : amount(amount) {}
    Enroll(string referral, int amount) : referral(referral), amount(amount) {}
};

unordered_map<string, Enroll> myMap;

void calcProfit(string name, int amount)
{
    Enroll& enroll = myMap[name];
    
    if (enroll.referral.empty() == false)
    {
        int profit = amount * 0.1f;
        amount -= profit;
        
        if (profit != 0)
        {
            calcProfit(enroll.referral, profit);
        }
    }
    
    enroll.amount += amount;
}

vector<int> solution(vector<string> enrolls, vector<string> referrals, vector<string> sellers, vector<int> amounts) {
    for (int i = 0; i < enrolls.size(); ++i)
    {
        string enroll = enrolls[i];
        string referral = referrals[i];
        
        myMap.emplace(enroll, Enroll(referral, 0));
    }
    
    for (int i = 0; i < sellers.size(); ++i)
    {
        string& seller = sellers[i];
        int amount = amounts[i] * 100;
        
        calcProfit(seller, amount);
    }
    
    vector<int> answer(enrolls.size());
    for (int i = 0; i < enrolls.size(); ++i)
    {
        Enroll& enroll = myMap[enrolls[i]];
        answer[i] = enroll.amount;
    }
    
    return answer;
}