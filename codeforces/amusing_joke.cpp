/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Amusing_Joke
 * @created     : Tuesday Feb 15, 2022 02:14:21 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)
#define REP(I,n,a) for(int i=I; i < n; i+=a) 

using ll = long long;

using namespace std ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // main code : 
    string a, b, c ; 
    cin >> a >> b >> c ; 
    a = a + b ; 
    sort(a.begin(),a.end()) ; 
    sort(c.begin(),c.end()) ; 
    if (a == c) cout << "YES\n" ; 
    else cout << "NO\n" ; 
    return 0 ; 
}


