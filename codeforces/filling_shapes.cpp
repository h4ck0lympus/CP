#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  
  int dp[n+1];
  dp[0] = 1;
  dp[1] = 0;
  for (int i=2; i <= n; i++) {
    dp[i] = dp[i-2] /* fill in one way*/ + dp[i-2] /* fill in another way */;
  }

  cout << dp[n] << "\n";
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

