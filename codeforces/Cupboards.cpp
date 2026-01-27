/**
 * @author      : HackOlympus (zeus@fedora)
 * @file        : Cupboards
 * @created     : Wednesday Jan 26, 2022 11:00:21 EST
 */

#include <bits/stdc++.h>

using namespace std ; 

int main()
{
    int n=0, lop=0, rop=0 ;
    cin >> n ; 
    int l[n], r[n] ; 
    
    for (int i=0; i < n; i++)
    {
        cin >> l[i] >> r[i] ; 
        if (l[i] == 1) 
        {
            lop++ ; 
        }
        if (r[i] == 1) 
        {
            rop++ ; 
        }
    }
    int t=0 ; 
    if (lop == n || rop == n)
    {   
        if (lop == n) 
        {
            for (int i=0; i < n ; i++) 
            {
                if (r[i] == 1) t++ ;  
            }
        }
        else if (rop == n) 
        {
            for (int i=0; i < n ; i++) 
            {
                if (l[i] == 1) t++ ;  
            }
        }
    }   
    else if (lop < rop)
    {
        for (int i=0; i < n ; i++)
        {
            if ((l[i] == r[i]) == 1)
            {
                t++ ;   
            }
            else if (l[i] == 1)
            {
                t+=2 ; 
            }
        }
    }
    else if (lop > rop)
    {
        for (int i=0; i < n ; i++)
        {
            if ((l[i] == r[i]) == 1)
            {
                t++ ;   
            }
            else if (r[i] == 1)
            {
                t+=2 ; 
            }
        }
    }
    cout << t << endl ; 
    return 0 ; 
}

