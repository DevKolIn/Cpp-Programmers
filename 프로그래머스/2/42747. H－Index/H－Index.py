def solution(citations):
    citations.sort(reverse=True)  # 인용 횟수를 내림차순으로 정렬
    h_index = 0

    for i, c in enumerate(citations, start=1):  # 1부터 시작하는 인덱스로 순회
        if c >= i:  # 인용 횟수가 현재 순위(i)보다 크거나 같으면 H-Index 가능
            h_index = i
        else:
            break  # 더 이상 조건을 만족하지 않으면 중단

    return h_index