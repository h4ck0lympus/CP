/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Ultra-Fast Mathematician
 * @created     : Sunday Jan 23, 2022 02:05:47 IST
 */

#include <bits/stdc++.h>

using namespace std ; 

// basically return xor of them 

int main()
{
    string n1, n2; 
    cin >> n1 >> n2 ; 

    for (int i=0; i < n1.length(); i++)
    {
        if (n1[i] == n2[i]) 
        {
            putchar('0') ; 
        }
        else
        {
            putchar('1') ; 
        }
    }
    return 0 ; 
}

