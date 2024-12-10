vector<int> solution(long long n) {
    vector<int> result;
    
    while (n > 0)
    {
        int num = n % 10;
        result.push_back(num);
        n /= 10;
    }
    
    return result;
}