n = int(input())
a = list(map(int, input().split()))
b=sum(a)/10
a.extend(a)
tmp=a[0];
l,r=0,1
if a[0]==b:
	print("Yes")
else:
	while a[l]>b and l<2*n-1:
		l+=1
	r=l+1
	while tmp<b and r<2*n:
		if(tmp==b):
			print("Yes")
		tmp+=a[r]
		r+=1
		while tmp>b:
			tmp-=a[l]
			l+=1
			if(tmp==b):
				print("Yes")
		if(tmp==b):
			print("Yes")
	if(r==2*n):
		print("No")