#!/usr/bin/env python3 

n, m = map(int, input().split())

line = []

line = list(map(int, input().split()))
print(line)

ind = 0
while (len(line) > 1):
    if (line[0] >= 0): 
        line[0] = line[0] - m 
        if (line[0] <= 0): 
            line.pop(0)
        line.append(line.pop(0))        
    ind += 1 

print(ind)
