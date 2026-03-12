#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<vector<char>> grid(n+1, vector<char>(n+1, 0));
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

  for (int i=0; i < n; i++) {
    string r; cin >> r;
    for (int j=0; j < n; j++) {
      grid[i][j] = r[j];
    }
  }

  if (grid[0][0] != '*') dp[0][0] = 1; // there is only one way to reach 0,0 i.e. do nothing

  // dp[X][Y] = ways to reach X,Y
  // now dp[i-1][j] = ways to reach i-1, j - we add this because it means how many ways we can reach 
  // i,j from up and dp[i][j-1] means how many ways to reach i,j from right
  for (int i=0; i < n; i++) {
    for (int j=0; j < n; j++) {
      if (grid[i][j] != '*') {
        if (i >= 1 && grid[i-1][j] != '*') dp[i][j] += (dp[i-1][j]) % MOD;
        if (j >= 1 && grid[i][j-1] != '*') dp[i][j] += (dp[i][j-1]) % MOD;
      }
    }
  }

  cout << dp[n-1][n-1] % MOD << "\n";
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

