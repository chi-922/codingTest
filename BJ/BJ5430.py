from collections import deque
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    order = input().strip()
    n = int(input())
    arr_str = input().strip()[1:-1]  # 대괄호 제거

    if arr_str:
        arr = deque(map(int, arr_str.split(',')))
    else:
        arr = deque()

    reversed_flag = False
    error_flag = False

    for cmd in order:
        if cmd == 'R':
            reversed_flag = not reversed_flag
        elif cmd == 'D':
            if not arr:
                print('error')
                error_flag = True
                break
            if reversed_flag:
                arr.pop()  # 뒤집힌 상태라면 뒤에서 제거
            else:
                arr.popleft()  # 정상 상태라면 앞에서 제거

    if not error_flag:
        if reversed_flag:
            arr.reverse()  # 마지막에 한 번만 뒤집기
        print('[' + ','.join(map(str, arr)) + ']')
