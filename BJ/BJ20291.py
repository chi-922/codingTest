import sys
input = sys.stdin.readline

n = int(input())
files = dict()

for i in range(n):
    file = list(input().strip().split('.'))
    if files.get(file[-1], False):
        files[file[-1]] += 1
    else:
        files[file[-1]] = 1

sorted_files = sorted(files.items())

for file, num in sorted_files:
    print(f'{file} {num}')
