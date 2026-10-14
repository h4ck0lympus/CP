#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, m; cin >> n >> m;
  map<string, set<char>> mp;

  // hashing ?????? 
  
  for (int i=0; i < n; i++) {
    string s; cin >> s;
    for (int j=0; j < s.size(); j++) {
      string p = s; p[j] = 'x';
      mp[p].insert(s[j]);
    }
  }

  for (int i=0; i < m; i++) {
    string t; cin >> t;
    bool ok = false;
    for (int j=0; j < t.size(); j++) {
      string p = t; p[j] = 'x';
      if (mp[p].size() > 1 || (mp[p].size() == 1 && mp[p].count(t[j]) == 0)) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES": "NO") << "\n";
  }
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}
