#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, x; cin >> n >> x;
  vector<int> coins(n, 0);
  vector<int> dp(x+1, 0);
  dp[0] = 1; // how many ways i can get sum = 0 - 1 way - doing nothing

  for (int i=0; i<n; i++) {
    cin >> coins[i];
  }

  for (int i=1; i <= x; i++) {
    for (int c: coins) {
      if (i-c >= 0) dp[i] += dp[i-c] % MOD; // ways to get sum i = sum # of ways i can get sum i - c
    }
  }

  cout << dp[x] % MOD << "\n";
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

