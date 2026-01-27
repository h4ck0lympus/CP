/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Arrival of the General
 * @created     : Tuesday Jan 25, 2022 10:38:35 IST
 */

#include <bits/stdc++.h>

using namespace std ; 

int main()
{
    int n ; 
    cin >> n ; 
    int max = 0, max_pos = 0,  min = INT_MAX,  min_pos = 0 ; 
    int a[n]  ;    
    for (int i=0; i < n; i++) 
    {
        cin >> a[i] ;
        if (a[i] > max) // NOTE : common mistake to add >= because this will unneccessarily include element positions
        {
            max = a[i] ; 
            max_pos = i ; 
        }
        if (a[i] <= min)  
        {
            min = a[i] ; 
            min_pos = i ;
        }
        
    }
    if (a[0] == max && a[n-1] == min) {
        cout << 0 << endl ;   
        return 0 ; 
    }
    // there is one extra because 1 swap will happen automatically 
    if (max_pos > min_pos) 
    {
        cout << (max_pos + (n-1-min_pos)) - 1 << endl ; 
        return 0;    
    }
    else  
    {
        cout << (max_pos + (n-1-min_pos))  << endl ;  
        return 0 ; 
    }
}
    

