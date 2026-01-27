/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Maximum Distance
 * @created     : Sunday Feb 06, 2022 14:04:35 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)
#define REP(I,n,a) for(int i=I; i < n; i+=a) 

using namespace std ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // main code : 
    int n ; 
    cin >> n ; 
    int x[n], y[n] ; 
    for (int i=0; i < n; i++) cin >> x[i] ; 
    for (int i=0; i < n; i++) cin >> y[i] ; 
    int maxsq = 0 ; 
    int dx, dy ; 
    for(int i=0; i < n ; i++) {
        for(int j=i+1; j < n ; j++){
            dx = x[i] - x[j] ;  
            dy = y[i] - y[j] ; 
            int sq = (dx*dx) + (dy*dy) ; 
            maxsq = max(sq, maxsq) ; 
        }
    }
    cout << maxsq << "\n" ; 

    return 0 ; 
}


