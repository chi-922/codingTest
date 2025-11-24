import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for tc in range(1, T + 1):
    N, K = map(int, input().split())
    numbers = input().strip()
    dq = deque(list())
    for num in numbers:
        dq.append(num)

    nums = set()
    rotation = 0
    while rotation <= N//4:
        for i in range(0, N, N//4):
            num = ''
            for j in range(i, i + N//4):
                num += dq[j]
            nums.add(int(num, 16))
        dq.rotate(1)
        rotation += 1

    sorted_nums = sorted(nums, reverse=True)

    for i, num in enumerate(sorted_nums):
        if i == K - 1:
            print(f'#{tc} {num}')
            break
