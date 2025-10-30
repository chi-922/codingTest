# 숫자 짝꿍

def solution(x, y):
    x_count = [0] * 10
    y_count = [0] * 10

    for i in x:
        x_count[int(i)] += 1

    for i in y:
        y_count[int(i)] += 1

    common = [0] * 10
    for i in range(10):
        common[i] = min(x_count[i], y_count[i])

    answer_parts = []
    for i in range(9, -1, -1):
        if common[i] > 0:
            answer_parts.append(str(i) * common[i])

    if not answer_parts:
        return "-1"

    answer = "".join(answer_parts)

    if answer[0] == '0':
        return "0"

    return answer
