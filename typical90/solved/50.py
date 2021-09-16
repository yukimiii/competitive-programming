from operator import mul
from functools import reduce
mod=1000000007
def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under
ans=0
N, K = map(int, input().split())
for i in range(N//K+1):
	ans=ans+cmb(N-K*i+i,i)
	ans=ans%mod
print(ans)