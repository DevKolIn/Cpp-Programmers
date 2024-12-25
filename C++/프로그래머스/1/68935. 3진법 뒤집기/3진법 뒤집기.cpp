int solution(int n) {
    int result = 0;

    while (n != 0)
    {
        int num = n % 3;
        result *= 3;
        result += num;
        n /= 3;
    }

    return result;
}