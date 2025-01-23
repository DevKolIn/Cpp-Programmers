using namespace std;

int Fibonacci(int n) {
    int prev1 = 0, prev2 = 1;
    int current;

    for (int i = 2; i <= n; ++i) {
        current = (prev1 + prev2) % 1234567;
        prev1 = prev2;
        prev2 = current;
    }

    return current;
}

int solution(int n) {
    return Fibonacci(n);
}