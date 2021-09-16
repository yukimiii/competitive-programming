import math
a,b,c =map(int,input().split())
g=math.gcd(a,math.gcd(b,c))
print(a//g+b//g+c//g-3)
