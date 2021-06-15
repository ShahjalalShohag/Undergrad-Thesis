from scipy import stats
n = int(input())
x1 = []
x2 = []
for _ in range(n):
  i, j = map(int, input().split())
  x1.append(i)
  x2.append(j)
tau, p_value = stats.kendalltau(x1, x2, )
print(tau, p_value)