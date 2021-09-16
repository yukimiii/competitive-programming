from itertools import groupby
n = int(input())
s = input()
ans = (n+1)*n//2
for key, group in groupby(s):
    m = len(list(group))
    ans -= m*(m+1)//2
print(ans)
