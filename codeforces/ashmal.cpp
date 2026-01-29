#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  int n; cin >> n; 
  vector<string> arr;

  string s; cin >> s;
  for (int i=1; i < n; i++) {
    string cs; cin >> cs;
    if ((cs + s) < (s + cs)) {
      // add to front
      s = cs + s;
    } else {
      s += cs;
    }
  }
  cout << s << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

