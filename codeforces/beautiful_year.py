#!/usr/bin/env python3 

inp = input() 


def isBeautiful(n: str):
    arr = list(n.replace(" ","")) # remove possilble spaces from input and convert everything to list
    for i in range(len(arr)):
        x = arr.pop()
        if str(x) in arr : 
            return False 
    return True 

def nextBeautiful(n: str):
    for i in range(int(n)+1,10000):
        if isBeautiful(str(i)):
            print(int(i))
            break 


nextBeautiful(inp)
