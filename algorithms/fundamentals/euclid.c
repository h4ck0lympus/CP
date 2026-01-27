/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : euclid
 * @created     : Wednesday Mar 29, 2023 13:38:33 MST
 */

#include <stdio.h>

int max(int a, int b) { return ((a > b) ? a : b); } 

int min(int a, int b) { return ((a < b) ? a : b); }

int gcd(int a, int b) 
{
    // assumption : a > b
    // a / b
    if (b == 0) {
        return a;    
    } else {
        return gcd(b, a % b); // b / remainder(a, b)
    }
}

int main (int argc, char *argv[])
{
    int x, y, res;
    printf("Enter first number: ");
    scanf("%d", &x); 
    printf("Enter second number: "); 
    scanf("%d", &y);
    
    res = gcd(max(x, y), min(x, y));
    printf("gcd = %d\n",res);

    return 0;
}

