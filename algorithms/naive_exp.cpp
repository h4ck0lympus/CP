/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : naive_exp
 * @created     : Wednesday Feb 23, 2022 01:30:18 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)

using ll = long long;

using namespace std ; 

long long naive_exp(int a, int n) ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    // main code : 
    int a = 13371337 ; 
    int n = 5; 
    cout << naive_exp(a,n) << "\n" ; 
    return 0 ; 
}

long long naive_exp(int a, int n) 
{
    ll res = 1 ; 
    while (n--) {
        res *= a ; 
    }
    return res ; 
}

