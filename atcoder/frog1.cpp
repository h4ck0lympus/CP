#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;

  vector<int> dp(n+1, INT_MAX);
  vector<int> h(n, 0);

  for (int i=0; i < n; i++) {
    cin >> h[i];
  }

  dp[0] = 0; // min cost to jump to itself is 0

  for (int i=1; i < n; i++) {
    if (i >= 1) dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
    if (i >= 2) dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
  }

  cout << dp[n-1] << "\n";
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

