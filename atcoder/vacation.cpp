#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);

  for (int i=0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  // dp[i][j] = max score on day i, if we choose jth activity
  vector<vector<int>> dp(n+1, vector<int>(3, INT_MIN)); 

  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  for (int i=1; i <= n; i++) {
    // if we choose activity a on day i
    dp[i][0] = a[i-1] + max(dp[i-1][1], dp[i-1][2]); // a[i-1] -> 1 idx to 0 idx

    dp[i][1] = b[i-1] + max(dp[i-1][0], dp[i-1][2]);

    dp[i][2] = c[i-1] + max(dp[i-1][0], dp[i-1][1]);
  }


  int mx = INT_MIN;
  for (int i=0; i < 3; i++) {
    mx = max(mx, dp[n][i]);
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



// greedy will fail here
  // int last_act = -1;
  //
  // for (int i=1; i <= n; i++) {
  //   dp[i] = dp[i-1];
  //   if (last_act == 0) {
  //     dp[i] += max(b[i-1], c[i-1]); 
  //     // set last act
  //   } else if (last_act == 1) {
  //     dp[i] += max(a[i-1], c[i-1]);
  //   } else if (last_act == 2) {
  //     dp[i] += max(a[i-1], b[i-1]);
  //   } else {
  //     dp[i] += max(max(a[i-1], b[i-1]), c[i-1]);
  //   }
  // }
  //
  // cout << dp[n] << "\n";
