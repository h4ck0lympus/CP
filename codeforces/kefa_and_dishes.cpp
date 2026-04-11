#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, m, k; cin >> n >> m>> k;
  vector<int> a(n), x(k), y(k), c(k);
  for (int i=0; i < n; i++) cin >> a[i];
  for (int i=0; i < k; i++) {
    cin >> x[i] >> y[i] >> c[i];
    x[i]--, y[i]--;
  }
  vector<vector<int>> bonus(n, vector<int>(n, 0));
  for (int i=0; i < k; i++) bonus[x[i]][y[i]] = c[i];
  // dp[mask][last] - max satisfaction
  vector<vector<int>> dp(1 << n, vector<int>(n, -INF));

  for (int i=0; i < n; i++) {
    dp[1 << i][i] = a[i];
  }

  for (int mask=0; mask < (1 << n); mask++) {
    int cnt = __builtin_popcountll(mask);
    if (cnt >= m) continue; // eaten more than portion size
    for (int last=0; last < n; last++) {
      for (int nxt = 0; nxt < n; nxt++) {
        if (mask & (1LL << nxt)) continue; // we can only eat dish which we have not eaten before
        int nmask = mask | (1LL << nxt);
        dp[nmask][nxt] = max(dp[nmask][nxt], dp[mask][last] + a[nxt] + bonus[last][nxt]);
      }
    }
  }

  int ans = 0;
  for (int mask = 0; mask < (1LL << n); mask++) {
    if (__builtin_popcountll(mask) != m) continue;
    for (int last = 0; last < n; last++) {
      ans = max(ans, dp[mask][last]);
    }
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
