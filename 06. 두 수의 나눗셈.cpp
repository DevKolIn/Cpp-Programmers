int solution(int num1, int num2) {
    float divided = (float)num1 / num2; /* 명시적 형변환을 통해 정밀도 손실을 막는다.  */
    return divided * 1000; /* 암묵적 형변환을 통해 소수점 이하 값을 버린다. */
}