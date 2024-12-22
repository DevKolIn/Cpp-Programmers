string solution(string phone_number) {
    for (int idx = 0; idx < phone_number.size() - 4; idx++)
    {
        phone_number[idx] = '*';
    }
    
    return phone_number;
}