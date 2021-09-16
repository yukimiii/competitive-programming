def ds(n, d):
    return(d*(n*n+n)+(10**d-1)//9-(100**d-1)//99)//2


l, r = map(int, input().split())
print((ds(r, len(str(r))) - ds(l - 1, len(str(l - 1)))) % (10 ** 9 + 7))
