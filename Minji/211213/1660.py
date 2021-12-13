import sys

n = int(sys.stdin.readline().strip())

dp = [0] * 130
dp2 = [999999] * (n + 1)
dp[1] = 1
dp2[1] = 1

for i in range(2, 130):
    dp[i] = dp[i - 1] + dp[i - 1] - dp[i - 2] + i

for i in range(2, n + 1):
    for j in range(2, 130):
        if dp[j] == i:
            dp2[i] = 1
            break
        elif dp[j - 1] <= i:
            dp2[i] = min(1 + dp2[i - dp[j - 1]], dp2[i])
            
print(dp2[n])

