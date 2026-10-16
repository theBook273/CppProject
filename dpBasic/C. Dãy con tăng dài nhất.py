def main():
    n = int(input())
    arr = input().split()
    arr = list((int(i) for i in arr))
    dp = list((1 for i in arr))

    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    print(max(dp))
    return 0


if __name__ == "__main__":
    main()
