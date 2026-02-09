/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Drinks
 * @created     : Tuesday Jan 25, 2022 12:19:46 IST
 */

#include <bits/stdc++.h>

using namespace std ; 

int main()
{
    int n=0 ; 
    float vol=0, tvol=0 ; 
    cin >> n ;
    int d[n] ; 
    for (int i=0; i < n; i++)
    {
        cin >> d[i];
        vol += d[i]; 
        tvol+= 100;
    }
    cout << fixed << setprecision(7) << vol/tvol * 100.0 << endl  ; 
}

