/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : fast_exp
 * @created     : Wednesday Feb 23, 2022 01:25:46 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)

using ll = long long;

using namespace std ; 

long long fast_exp(int a, int n) ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    // main code : 
    int a = 13371337 ; 
    int n = 5 ; 
    cout << fast_exp(a,n) << "\n" ; 
    return 0 ; 
}

long long fast_exp(int a, int n) 
{
    if (n == 0) {
        return 1 ; 
    } else if (n == 1) {
        return a ; 
    } else {
        ll r = fast_exp(a,n / 2) ; 
        if (n % 2 ) {
            return r * r * a ; 
        } else {
            return r * r ; 
        }
    }
}
