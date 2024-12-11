long long solution(long long num) {
    long long result = 0;
    priority_queue<int> pq;
    
    while (num > 0)
    {
        int remain = num % 10;
        pq.push(remain);
        num /= 10;
    }
    
    while (!pq.empty())
    {
        int topNum = pq.top();
        result *= 10;
        result += topNum;
        pq.pop();
    }
    
    return result;
}