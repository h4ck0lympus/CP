/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : System_of_Equations
 * @created     : Friday Feb 18, 2022 02:37:38 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)

using ll = long long;

using namespace std ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    // main code : 
    int n, m ; 
    cin >> n >> m ; 
    // a * a + b = n ; a + b * b = m 
    int ans = 0 ; 
    for (int a=0; a <=500; a++) {
        for (int b=0; b <= 500; b++) {
            int x = a * a + b ; 
            int y = a + b * b ; 
            if (x == n && y == m) {
                ans++ ; 
            }
        }
    }
    cout << ans << "\n" ; 
    return 0 ; 
}


