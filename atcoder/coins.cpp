#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<double> p(n+1);

  for (int i=1; i <= n; i++) {
    cin >> p[i];
  }

  vector<vector<double>> dp(n+1, vector<double>(n+1, 0)); // dp[i][j] = P(in first i coins, j coins are heads)
  dp[0][0] = 1; // in first 0 coins, 0 coins are heads 100% probability ...
  dp[0][n] = 0; // in first 0 coins, all coins are heads 0%
                
  for (int i=1; i <= n; i++) {
    for (int j=0; j <= n; j++) {
      // dp[i][j] = in first i-1 coins, j-1 coins are head 
      // OR
      // in first i-1 coins, all j are head and last coin is tails
      if (j == 0) dp[i][j] = dp[i-1][0] * (1 - p[i]); // all i-1 coins are tails + ith coins is tails as well
      else dp[i][j] = (dp[i-1][j-1] * p[i]) + (dp[i-1][j] * (1 - p[i]));
    }
  }

  double ans = 0; // all i-1 coins are tails + ith coins is tails as well
  for (int i=(n/2 + 1); i <= n; i++) {
    ans += dp[n][i];
  }

  cout << ans << "\n";
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

