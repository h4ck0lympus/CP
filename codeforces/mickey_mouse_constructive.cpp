#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
//const int MOD = (int) (1e9 + 7);
const int MOD = 676767677;

void solve() {
  int x, y; cin >> x >> y;
  int s = x-y;
  int ans = 0;

  for (int i=1; i <= abs(s); i++) {
    if (s % i == 0) ans = (ans + 1) % MOD;
  }

  if (s == 0) ans = 1;

  cout << ans << "\n";
  for (int i=0; i < x; i++) {
    cout << "1 ";
  }
  for (int i=0; i < y; i++) {
    cout << "-1 ";
  }
  cout << "\n";
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

