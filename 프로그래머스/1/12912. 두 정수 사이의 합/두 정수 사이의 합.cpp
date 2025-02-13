#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    return static_cast<long long>(a + b) * (abs(a - b) + 1) / 2;
}