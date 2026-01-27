/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : Petya and Strings
 * @created     : Tuesday Jan 25, 2022 13:51:07 IST
 */

#include <bits/stdc++.h>

using namespace std ; 

int main()
{
    string a, b ; 
    int i, j ; 
    cin >> a >> b ; 
    for (i=0, j=0; i < a.length() && j < b.length() && tolower(a[i]) == tolower(b[j]) ; i++, j++) ; 
    if ((i != a.length() - 1 || j !=b.length()) && (tolower(a[i]) - tolower(b[j]) > 0) ) 
    {
        cout << 1 << endl ;
        return 0 ; 
    }
    else if ((i != a.length() - 1 || j != b.length()) && (tolower(a[i]) - tolower(b[j]) < 0) ) 
    {
        cout << -1 << endl ; 
        return 0 ; 
    }
    else cout << 0 << endl ; 
    return 0 ; 
}

