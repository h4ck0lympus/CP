/**
 * @author      : HackOlympus (zeus@fedora)
 * @file        : Effective Approach
 * @created     : Thursday Jan 27, 2022 04:05:03 EST
 */

#include <bits/stdc++.h>

using namespace std ; 

int find(int arr[], int x, int n) ; 

int main()
{
    int n, m, r1=0, r2=0, x, y  ; 
    cin >> n ;  
    int an[n] ; 
    for (int i=0; i < n; i++) cin >> an[i] ; 
    cin >> m ; 
    int am[m] ; 
    for (int i=0; i<m; i++) cin >> am[i]  ; 
    
    for (int i=0; i < m; i++)
    {
        x = find(an, am[i], n) ; 
        r1 += x ; 
        y = (n-x) + 1;
        r2 += y ;
        printf("x = %d\ny = %d\nquery = %d\n",x,y,am[i]) ;
    }
    cout << r1 << " " << r2 << endl ; 
    return 0 ; 
}

int find(int arr[], int x, int n)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i] == x)  return i+1 ; // return number of operations performed  
    }
    return -1 ; 
}
