#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> c(n);
  for (int i=0; i < n; i++) cin >> c[i];
  // dp[l][r] = min number of seconds to clear range [l, r]
  // if [l,r] is palindrome - move = 1
  // else check for different splits
  vector<vector<int>> dp(n, vector<int>(n, INF));
  for (int i=0; i < n; i++) dp[i][i] = 1;
  for (int len=2; len <= n; len++) {
    for (int l=0; l + len - 1 < n ; l++) {
      int r = l + len - 1;
      if (c[l] == c[r]) {
        if (l+1 <= r-1) dp[l][r] = dp[l+1][r-1];
        else dp[l][r] = 1;
      }
      for (int k=l; k < r; k++) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
      }
    }
  }
  cout << dp[0][n-1] << "\n";
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

