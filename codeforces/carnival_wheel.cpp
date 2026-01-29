#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  // l and t both are very small so we can bruteforce
  int l, a, b; cin >> l >> a >> b;
  int mx = a;
  for (int i=0; i < l; i++) {
    mx = max(mx, (a + (i+1) * b) % l) ;
  }
  cout << mx << "\n";
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

