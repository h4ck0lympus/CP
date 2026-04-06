#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int a, b; cin >> a >> b;

  // dp[i][j] = min number of moves needed for rectangle of dimension i x j
  int mx = max(a, b);
  vector<vector<int>> dp(mx+1, vector<int>(mx+1, INF));

  for (int i=0; i <= mx; i++) dp[i][i] = 0; // 0 moves needed if already a square
 
  for (int i=1; i <= a; i++) { 
    for (int j=1; j <= b; j++) {
      // k = all possible cut positions 
      for (int k=1; k < i; k++) {  // cut positons for horizontal cut
        dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
        // printf("dp[%lld][%lld] = %lld\n", i, j, dp[i][j]);
      }

      // printf("\n------\n");

      for (int k=1; k < j; k++) { // cut positons for vertical cut
        dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
        // printf("dp[%lld][%lld] = %lld\n", i, j, dp[i][j]);
      }

    }
  }

  cout << dp[a][b] << "\n";
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

