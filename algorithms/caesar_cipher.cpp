/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : caesar_cipher
 * @created     : Monday Feb 21, 2022 21:00:15 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)

using ll = long long;

using namespace std ; 

string caesar_enc(string s) ; 

int main(int argc, char *argv[])
{
    //ios::sync_with_stdio(0);
    //cin.tie(0); //cout.tie(0);    
    // main code : 
    if (argc < 2) {
        printf("Supply argument\n") ; 
        exit(0) ; 
    }
    cout << caesar_enc(argv[1]) << "\n" ; 
    return 0 ; 
}

string caesar_enc(string s)
{
    string res = "" ; 
    for (char c: s) {
        printf("%c = %d\n",c,c) ; 
        if (c >= 'A'&& c <= 'Z') {
            char x = ((c + 1) % 'Z') + 'A' ;   
            res += x ;
            cout << (int)x << "\n" ; 
        } else if (c >= 'a' && c <= 'z' ) {
            char x = ((c + 1) % 'z') + 'a' ; 
            res += x ;
            cout << (int)x << "\n" ; 
        } else {
            res += c ; 
        }
    }
    return res ; 
}

