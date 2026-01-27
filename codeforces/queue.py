#!/usr/bin/env python3 
 
n, t = map(int, input().split())
s = list(input())

if n == 1: 
    pass
else : 
    for _ in range(t):
        i=0
        while (i<n): 
            if s[i] == 'B' and s[i+1] == 'G':
                t = s[i+1]
                s[i+1] = s[i]
                s[i] = t
                i+=1 
            i+=1
            if (i >= n-1) : break 
     
print("".join(s))
