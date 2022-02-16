# class Solution:
#     def maximalSquare(self, matrix: List[List[str]]) -> int:
#         n = len(matrix)
#         m = len(matrix[0])
#         dp = [[0] * m] * n
#         res = 0
#         for i in range(n):
#             for j in range(m):
#                 dp[i][j] = (0, 1)[matrix[i][j] == "1"]
#                 if dp[i][j] == 1:
#                     res = 1
#         print(dp)
#         for i in range(1, n):
#             for j in range(1, m):
#                 print(dp[i][j], end=' ')
#                 if dp[i][j] == 1:
#                     dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j],
#                                     dp[i][j - 1])
#                 res = max(res, dp[i][j])
#             print("")
#         return res * res


n = int(input())
m = int(input())
matrix = [] * n

for i in range(n):
    matrix[i] = [input().split()]

dp = [[0] * m] * n

for i in range(n):
    for j in range(m):
        dp[i][j] = int(matrix[i][j])
        print(dp[i])
        # print(matrix[i])
        print(dp)
# print(Solution().maximalSquare(matrix))