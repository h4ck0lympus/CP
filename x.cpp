/*
ID: vjuneja1
TASK: 
LANG: C++                 
*/
#include "bits/stdc++.h"
// #include "dbg.h"
using namespace std;

#define TASK ""
#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> dp(n+1);
  dp[0] = 1;  // one way to get 0 sum - do nothing
  dp[1] = 1; // one way to get 1 sum - throw 1
  for (int i=2; i <= n; i++) {
    dp[i] = 0;
    for (int j=1; j <= 6; j++) {
      if (i - j >= 0) dp[i] += dp[i-j] % MOD;
    }
    dp[i] = dp[i] % MOD;
  }
  cout << dp[n] << "\n";
}

#undef int
int main() {
  // freopen(TASK ".in", "r", stdin);
  // freopen(TASK ".out", "w", stdout);
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

