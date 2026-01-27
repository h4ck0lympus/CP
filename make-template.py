#!/usr/bin/env python3 

#train.usaco.org template generator

from string import Template 
from os import mkdir, chmod 
import sys, stat 

def get_template(task):
    t = Template("""/*
ID: vishal_7
TASK: $task 
LANG: C++
*/

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)
#define REP(I,n,a) for(int i=I; i < n; i+=a) 

using namespace std ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("$task_input", "r", stdin);
    freopen("$task_output", "w", stdout);
    
    // main code : 

    return 0 ; 
}
""")
    return t.substitute({'task':task, 'task_input':task+ '.in','task_output':task + '.out'})

def get_run_template(task):
    temp = "#!/usr/bin/env sh\n"
    temp += "tput bold ; echo compiling\n"
    temp += f"g++ {task}.cpp -Wall -o {task} && ./{task}\n"
    temp += "echo output :\n"
    temp += f"cat {task}.out"
    return temp


def main():
    if (len(sys.argv) != 2 ):
        print("usage: ./make-template.py task_name")
        exit(-1)
    
    taskname = sys.argv[1]
    template = get_template(taskname)
    run_template = get_run_template(taskname) 
    mkdir(taskname)
    with open(f"{taskname}/{taskname}.cpp",'w+') as f :
        f.write(template)
    with open(f"{taskname}/run","w") as f : 
        f.write(run_template)
    chmod(f"{taskname}/run",stat.S_IRWXU)
    open(f"{taskname}/{taskname}.out","w") 
    open(f"{taskname}/{taskname}.in","w") 
    print("Done!")


main()
