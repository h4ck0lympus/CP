#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, w; cin >> n >> w; // num items, max sum of weights
  vector<int> weights(n), values(n);

  int val_sum = 0;
  int max_wt = INT_MIN;
  for (int i=0; i < n; i++) {
    cin >> weights[i] >> values[i];  
    val_sum += values[i];
    max_wt = max(max_wt, weights[i]);
  }

  vector<vector<int>> dp(n+1, vector<int>(val_sum+1, INF)); // dp[i][j] = min wt to achieve value j using the first i items
 
  dp[0][0] = 0; // 0 weight if we take first 0 items, to achieve value = 0

  for (int i=1; i <= n; i++) {
    int val = values[i-1]; // val of current item
    int wt = weights[i-1]; // weight of current item
    for (int j=0; j <= val_sum; j++) {
      if (j >= val) dp[i][j] = min(dp[i-1][j], dp[i-1][j-val] + wt);
      else dp[i][j] = dp[i-1][j];
    }
  }

  for (int j=val_sum; j >= 0; j--) {
    if (dp[n][j] <= w) {
      cout << j << "\n";
      break;
    }
  }
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

