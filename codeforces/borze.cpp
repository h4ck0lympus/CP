#include <bits/stdc++.h>

using namespace std ; 

int main()
{
    char s[201] = {0} ;
    cin >> s ;
    for (int i=0; s[i] != '\0' ; i++)
    {
        if (s[i] == '.') 
        {
           cout << '0' ;  
        }
        else if (s[i] == '-' && s[i+1] == '.') 
        {
            cout << '1' ;
            ++i ; 
        }
        else if (s[i] == '-' && s[i+1] == '-')
        {
            cout << '2' ; 
            ++i;
        }
    }
    return 0 ;  

}

