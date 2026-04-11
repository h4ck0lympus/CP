#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n,a,b,c; cin >> n >> a >> b >> c;
  vector<int> dp(n+1, -INF);
  dp[0] = 0;
  for (int i=1; i <= n; i++) {
    if (i-a>=0) dp[i] = max(dp[i], dp[i-a] + 1);
    if (i-b>=0) dp[i] = max(dp[i], dp[i-b] + 1);
    if (i-c>=0) dp[i] = max(dp[i], dp[i-c] + 1);
  }
  cout << dp[n] << "\n";
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
