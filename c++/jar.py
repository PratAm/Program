#!/usr/bin/python
in1 = map(int,raw_input().split(' '))
N = in1[0]
M = in1[1]
l = [0]*N
print l
for _ in range(M):
	in2 = map(int,raw_input().split())
	a = in2[0];b=in2[1];k=in2[2]
	for i in range(a-1,b):
		print i
		l[i]+=k
		print l
x = sum(l)
print x
print x/M
    
