/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : beautiful_year
 * @created     : Saturday Jan 22, 2022 19:00:31 IST
 */

/* minimum year number which is strictly larger than the given one and has only distinct digits. */

#include <bits/stdc++.h>

using namespace std ; 

int isBeautiful(int n) ; 
int NextBeautiful(int n) ; 

int main()
{
    int n ; 
    cin >> n ;
    cout << NextBeautiful(n) ; 
}

int isBeautiful(int n)
{
    int num_arr[4] ; 
    for (int i=3; i!= -1 && n != 0; i--) 
    {
        num_arr[i] = n % 10 ; 
        n = n / 10 ; 
    }
    
    n = 4 ; 
    while (n--)
    {
        int r = num_arr[n] ; 
        for (int i = 0 ; i < n; i++)
        {
            if (r == num_arr[i]) return 0 ;  
        }
    }
    return 1 ; 
}

int NextBeautiful(int n)
{
    for (int i=n+1; i < 10000; i++)
    {
        if (isBeautiful(i)) return i ; 
    }
    return -1 ; 
}
