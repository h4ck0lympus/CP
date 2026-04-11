#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> s(n);
  for (int i=0; i < n; i++) cin >> s[i];
  sort(s.begin(), s.end());
  vector<vector<int>> dp(n, vector<int>(n, INF)); // dp[l][r] = min possible d in [l, r]
  for (int i=0; i < n; i++) dp[i][i] = 0;
  for (int len=2; len <= n; len++) {
    for (int l=0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      dp[l][r] = min(dp[l+1][r], dp[l][r-1]) + s[r] - s[l];
    }
  }
  cout << dp[0][n-1] <<"\n";
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
