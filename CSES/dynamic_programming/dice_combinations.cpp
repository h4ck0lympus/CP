#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// TOP DOWN APPROACH (will get runtime error for bit n because of stack overflow)
// int f(int n, vector<int>& dp) {
//    // number of possible values we can get in first valid throw
//    // so if it's 1 - only one possible value - 1
//    // if it's 2 - only 2 possible values - 1, 2
//   int k = min(n, 6LL);
//   if (dp[n] != -1) return dp[n];
//   int ways = 0;
//   for (int i=1; i <= k; i++) {
//     ways += f(n-i, dp) % MOD;
//   }
//   dp[n] = ways % MOD;
//   return dp[n];
// }

void solve() {
  int n; cin >> n;
  // vector<int> dp(n+1, -1);
  vector<int> dp(n+1, 0);

  dp[0]=1; // one one way to get 0, DO NOTHING...
  dp[1]=1; // only one way to get throw of 1

  for (int i=2; i <= n; i++) {
    for (int j=1; j <= 6; j++) {
      if (i - j >= 0) dp[i] += dp[i-j] % MOD;
    }
  }

  cout << dp[n] % MOD << "\n";

  // cout << f(n, dp) << "\n";
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

