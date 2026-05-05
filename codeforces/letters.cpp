#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  string s1, s2; 
  getline(cin, s1);
  getline(cin, s2);
  map<char, int> f;
  for (char c: s1) {
    if (c != ' ') f[c]++;
  }
  for (char c: s2) {
    if (c == ' ') continue;
    if (f[c] == 0) {
      cout << "NO\n";
      return;
    }
    f[c]--;
  }

  cout << "YES\n";
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

