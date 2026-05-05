#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) (1e18);
const int MOD = (int) (1e9 + 7);

void solve() {
  int N, M, K; cin >> N >> M >> K;
  vector<vector<int>> grid(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(K + 1, -INF)));

  dp[0][0][0] = grid[0][0];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (i == 0 && j == 0) continue;

      for (int k = 0; k <= K; k++) {
        // from top
        if (i > 0) {
          if (grid[i][j] == -1) {
            if (k > 0 && dp[i - 1][j][k - 1] != -INF) {
              dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
            }
          } else {
            if (dp[i - 1][j][k] != -INF) {
              dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + grid[i][j]);
            }
          }
        }

        // from left
        if (j > 0) {
          if (grid[i][j] == -1) {
            if (k > 0 && dp[i][j - 1][k - 1] != -INF) {
              dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
            }
          } else {
            if (dp[i][j - 1][k] != -INF) {
              dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + grid[i][j]);
            }
          }
        }
      }
    }
  }

  int ans = -INF;
  for (int k = 0; k <= K; k++) {
    ans = max(ans, dp[N - 1][M - 1][k]);
  }

  if (ans == -INF) cout << -1 << "\n";
  else cout << ans << "\n";
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
