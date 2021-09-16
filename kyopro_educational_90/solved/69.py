n,k =map(int,input().split())
print(pow(max(k-2,0),max(n-2,0),10**9+7)*pow((k-1),min(1,n-1))*k%(10**9+7))