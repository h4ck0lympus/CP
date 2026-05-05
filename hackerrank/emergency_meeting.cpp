#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int)1e18;
const int MOD = (int)(1e9 + 7);

void solve() {
  map<string, int> mp;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    mp[s]++;
  }

  int mx = 0;
  for (auto [name, cnt] : mp) {
    mx = max(mx, cnt);
  }

  int c = 0;
  string ans = "";
  for (auto [name, cnt] : mp) {
    if (cnt == mx) {
      c++;
      ans = name;
    }
  }

  if (c > 1)cout << "TIE\n";
  else cout << ans << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--)
    solve();
#else
  solve();
#endif
}
