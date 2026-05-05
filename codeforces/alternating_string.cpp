#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  string s; cin >> s;
  // char c = s[0];
  // int a = -1, b = -1;
  int c=0;
  for (int i=0; i < s.size()-1; i++) {
    if (s[i] == s[i+1]) c++;
  }
  cout << ((c <= 2) ? "YES\n": "NO\n");
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

