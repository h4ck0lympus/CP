#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, m; cin >> n >> m;
  vector<int> arr(n);
  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  // dp[i][k] = num of possibilities for ith idx such that element @ ith idx = k
  vector<vector<int>> dp(n, vector<int>(m+1, 0));

  // base case
  dp[0][0] = 0; // values start from 1 so 0 is not possible
  for (int i=1; i <= m; i++) {
    if (arr[0] == 0)  {
      dp[0][i] = 1;
    } else {
      dp[0][i] = (arr[0] == i) ? 1: 0;
    }
  }

  for (int i=1; i < n; i++) {
    for (int j=1; j <= m; j++) {
      if (arr[i] == 0) {
        // if value at current idx == 0
        // then num possiblities for current idx is unknown for m cases (m being the possible value at current idx)
        if (j == m) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
      } else {
        // if value is known then 0 possiblities for other cases where k != arr[i] (dp[i][k]) 
        if (j == m) dp[i][j] = (arr[i] == j) ? (dp[i-1][j-1] + dp[i-1][j]) % MOD: 0;
        else dp[i][j] = (arr[i] == j) ? (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD: 0;
      }
    }
  }

  int ans = 0;
  // last value can be any element from 1 to m
  // so we take summation of possiblities from 1 to m
  for (int i=1; i <= m; i++) {
    ans += dp[n-1][i] % MOD;

  }
  cout << ans % MOD << "\n";
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

