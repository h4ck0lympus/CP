/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Insomnia cure
 * @created     : Tuesday Jan 25, 2022 12:43:16 IST
 */

#include <bits/stdc++.h>

using namespace std ; 

int main()
{
    int k,l,m,n,d ; 
    cin >> k >> l >> m >> n >> d ; 
    int arr[d+1] ; 
    arr[0] = 0 ; 
    for (int i = 1; i < d+1; i++)
    {
        arr[i] = 1;  
    }

    for (int i = k; i < d+1 ; i+=k)
    {
        if (arr[i]) arr[i] = 0 ; 
    }
    for (int i = l; i < d+1 ; i+=l)
    {
        if (arr[i]) arr[i] = 0 ; 
    }
    for (int i = m; i < d+1 ; i+=m)
    {
        if (arr[i]) arr[i] = 0 ; 
    }
    for (int i = n; i < d+1 ; i+=n)
    {
        if (arr[i]) arr[i] = 0 ; 
    }
    int c = 0 ; 
    for (int i = 0; i<d+1; i++) if (arr[i] == 0) c++ ; 
    cout << c-1 << endl ; 

}

