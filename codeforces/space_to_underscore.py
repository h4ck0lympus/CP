#!/usr/bin/env python3 

import os 

for i in os.listdir() :
    if (len(i.split()) >= 2) : 
        src = "./" + " ".join(i.split()) 
        des = "./" + "_".join(i.split()) 
        os.rename(src,des) 

