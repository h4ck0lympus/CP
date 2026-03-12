#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int>arr(n+1);

  for (int i=1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n+1, 0); // dp[n] = score when starting point is n
  dp[n] = arr[n];

  int mx = dp[n];
  for (int i=n-1; i >= 1; i--) {
    dp[i] = arr[i];
    if (i + arr[i] <= n) dp[i] += dp[i+arr[i]];
    mx = max(mx, dp[i]);
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

