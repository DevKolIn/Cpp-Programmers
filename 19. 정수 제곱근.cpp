long long solution(long long n) {
    long long result = -1;
    float sqrtN = sqrt(n);
    int integerSqrtN = static_cast<int>(sqrtN);
    
    if ((sqrtN - integerSqrtN) == 0)
    {
        integerSqrtN += 1;
        result = static_cast<long long>(integerSqrtN) * integerSqrtN;
    }
    
    return result;
}