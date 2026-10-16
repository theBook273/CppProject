from collections import deque

basecase = deque([1, 2, 4, 8, 16, 32])
n = int(input())
mod = 1e9 + 7
if n <= len(basecase):
    print(basecase[n - 1])
else:
    for i in range(6, n):
        tong = 0
        for x in basecase:
            tong = int(tong % mod) + int(x % mod)
            tong = int(tong % mod)
        basecase.popleft()
        basecase.append(tong)
    print(int(basecase[-1] % mod))
