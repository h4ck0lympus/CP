// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include <bits/stdc++.h>

using namespace std;

int kmpMax(string s, int max) {
    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int m = pi[i - 1];
        while (m and s[m] != s[i]) {
            m = pi[m];
        }
        if (m) {
            pi[i] = m + 1;
        } else {
            pi[i] = s[i] == s[0];
        }
    }
    int res = pi[n - 1];
    while (res > max) {
        res = pi[res - 1];
    }
    return res;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        int c = 0;
        for (int i = 0; i < n and s[i] == s[n - 1 - i]; i++) {
            c = i + 1;
        }
        if (c == n) {
            cout << s << endl;
            continue;
        }
        string pfix = s.substr(0, c);
        string sfix = s.substr(n - c, c);
        string u = s.substr(c, n - 2 * c);
        int m = u.length();
        string r = "";
        for (int i = 0; i < m; i++) {
            r += u[m - 1 - i];
        }
        int left = kmpMax(u + r, m);
        int right = kmpMax(r + u, m);
        if (left > right) {
            cout << (pfix + u.substr(0, left) + sfix) << endl;
        } else {
            cout << (pfix + r.substr(0, right) + sfix) << endl;
        }
    }
}

