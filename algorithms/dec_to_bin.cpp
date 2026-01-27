/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : dec_to_bin
 * @created     : Tuesday Feb 15, 2022 17:19:04 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)
#define REP(I,n,a) for(int i=I; i < n; i+=a) 

using ll = long long;

using namespace std ; 

string dec_to_bin(int n) 
{
    string bin = "" ; 
    while (n) {
        int r = n % 2 ; 
        n /= 2 ; 
        bin += (char)'0' + r ; 
    }
    reverse(bin.begin(),bin.end()) ; 
    return bin ;  
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0) ; 
    // main code : 
    int n ; cin >> n ; 
    cout << dec_to_bin(n) << "\n"; 
    return 0 ; 
}


