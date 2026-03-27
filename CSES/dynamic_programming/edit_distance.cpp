#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// 1 <= n, m <= 5000
// max n * m = 25e6 (< 1e8)
void solve() {
  string x, y; cin >> x >> y;
  int n = x.length(), m = y.length();
  
  // dp[i][j] = edit distance till ith idx of string x and jth idx of string y
  vector<vector<int>> dp(n+1, vector<int>(m+1, INF));

  // first string is empty, comparing with second string till ith idx - add the chars
  for (int i=0; i <= m; i++) {
    dp[0][i] = i;
  }

  for (int i=0; i <= n; i++) {
    dp[i][0] = i;
  }
  
  for (int i=1; i <= n; i++)  {
    for (int j=1; j <= m; j++) {
      if (x[i-1] != y[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1); // replace
      else dp[i][j] = min(dp[i][j], dp[i-1][j-1]); // match

      dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); // insert
      
      // remove - we are removing a char from first string so comparing i-1 with j
      dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); // replace
    }
  }

  cout << dp[n][m] << "\n";
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

