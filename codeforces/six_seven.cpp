#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int MOD = (int)(1e9 + 7);

void solve() {
  int n; cin >> n;
  int mx = INT_MIN;
  vector<int> xs;
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    xs.push_back(x);
    mx = max(mx, x);
  }
  vector<int> dp(mx+1, 0);
  dp[0] = 1;

  for (int i=0; i <= mx; i++) {
    if (i >= 67) dp[i] = (dp[i] + dp[i - 67]) % MOD;
    if (i >= 76) dp[i] = (dp[i] + dp[i - 76]) % MOD;
  }

  for (int i=0; i < n; i++) {
    cout << dp[xs[i]] << "\n";
  }
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

