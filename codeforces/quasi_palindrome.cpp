#include "bits/stdc++.h"

using namespace std;

void solve()
{
    string x;
    cin >> x;

    int last_non_zero = x.size() - 1;
    for (int i=x.size()-1; i >= 0; i--) {
        if (x[i] != '0') {
            last_non_zero = i;
            break;
        }
    }

    x = x.substr(0, last_non_zero+1);
    string xr = x;
    reverse(xr.begin(), xr.end());
    
    if (x == xr)  {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    solve();
}
