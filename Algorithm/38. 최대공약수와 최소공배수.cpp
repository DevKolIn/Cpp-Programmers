#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int lcd(int a, int b)
{
    return a * b / gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> result;
    result.push_back(gcd(n,m));
    result.push_back(lcd(n,m));
    
    return result;
}