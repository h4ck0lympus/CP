/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : sieve_of_eratosthenes
 * @created     : Thursday Mar 30, 2023 10:09:21 MST
 */

#include <stdio.h> 
#include <string.h>
#include <math.h> 

#define LEN 1000

int sieve_arr[LEN] = {0}; 

void sieve()  
{
    for (int i=2; i < sqrt(LEN); i++) 
    {
        for (int num=(2*i); num < LEN; num += i) 
        {
            if (sieve_arr[num] == 0) sieve_arr[num] = 1;
        }
    } 
}


int main (int argc, char *argv[])
{
    int n;  
    sieve_arr[0] = 1;
    sieve_arr[1] = 1;
    sieve(); 
    
    printf("Enter number: ");
    scanf("%d", &n);
    
    if (!(sieve_arr[n])) {
        printf("%d is prime\n", n);
    } else {
        puts("not prime");
    }

    return 0;
}
