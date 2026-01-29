#include "bits/stdc++.h"
#include <ios>

using namespace std;

#define int long long

int n;
vector<vector<int>> freq;

int shit(int x, char ch) {
  // count shit till x
  int times_repeated = x / n;
  int left_out = x % n;

  int crap = times_repeated * freq[n][ch - 'a'] + freq[left_out][ch-'a'];
  return crap;
}

void solve() {
  int q;
  cin >> n >> q;
  string s;
  cin >> s;

  // max string length is 1e4
  // there are 26 chars so we can make a frequency map
  // to store occurence of each char ch till length n of string
  // times a letter ch appears in original string n
  
  vector<int> f(26, 0); // OR we can use vector to make memory usage dynamic

  freq.push_back(f); // fucking 1 indexing
  for (int i = 0; i < n; i++) {
    char ch = s[i];
    f[ch - 'a']++;
    freq.push_back(f);
  }

  while (q--) {
    int l, r;
    char ch;
    cin >> l >> r >> ch;
    // if we never 
    if (r <= n) {
      cout << freq[r][ch - 'a'] - freq[l-1][ch-'a'] << endl;
    } else {
      cout << shit(r, ch) - shit(l-1, ch) << endl;
    }
  }
}

#ifdef int
#undef int
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    freq.clear(); // FUCKING RESET
    solve();
  }
}


    // int times_repeated = (r - l + 1) / n;
    // int skipped = (r - 1) % n;
    //
    // int b2 = freq[r][c - 'a'] * times_repeated;
    // int a2 = freq[l][c - 'a'] * times_repeated; 
    //
    // int sk = freq[skipped][c-'a'];
    //
    // cout << (b2-a2 - sk) << endl;
    
    // occurence of c till r
    // int b = freq[r][c - 'a'];
    // int a = freq[l][c - 'a'];
    // cout << b - a << endl;
