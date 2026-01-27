/**
 * @author      : HackOlympus (zeus@fedora)
 * @file        : Dima and Friends
 * @created     : Friday Jan 28, 2022 23:10:40 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)

using namespace std ; 

// if (sum of dima + sum of friends) % n != 1 (because if it is one it will point to dima) 
// n is total friends including dima  

int n, sum ; 

int main()
{
    cin >> n ; 
    int a[n]; 
    FOR(n) 
    {
        cin >> a[i] ;
        sum+= a[i] ; 
    }
    int res = 0 ; 
    
    for (int x=1; x<=5; x++) // starting from 1 because x cant be 0
    {
        if ((x+sum) % (n+1) != 1) res++ ; 
    }
    cout << res << endl ; 
    return 0 ; 
}


