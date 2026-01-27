/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : PanoramixPrediction
 * @created     : Saturday Jan 22, 2022 23:12:52 IST
 */

#include <bits/stdc++.h>

using namespace std ; 

// basically implement a sieve and return next prime number after number n 

int getPrime(int n) ; 
 
int main()
{
    int n1, n2; 
    cin >> n1 >> n2 ; // no need to check if number is prime or not cuz its guaranteed 
    int x = getPrime(n1) ;
    if (x == n2) cout << "YES" ;
    else cout << "NO" ; 
    return 0 ; 
}

int getPrime(int n)
{
    int arr[100] ; 
    arr[0] = 0 ; 
    arr[1] = 0 ; 
    for (int i=2; i < 100 ; i++) arr[i] = 1 ; 
    for (int i=0; i < 100 ; i++) 
    {
        if (arr[i]) 
            for (int j=2*i; j < 100 ; j+=i) 
                arr[j] = 0 ; 
    }

    for (int i = n+1; i<100; i++)
    {
        if (arr[i]) return i ; 
    }
    return -1 ; 
}
