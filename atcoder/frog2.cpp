#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, k; cin >> n >> k;
  vector<int> h(n);

  for (int i=0; i < n; i++) {
    cin >> h[i];
  }

  vector<int> dp(n+1, INT_MAX);
  dp[0] = 0; // minimum cost to reach this stone from any of the previous k stones

  for (int i=0; i < n; i++) { // starting stone
    for (int j=i+1; j <= i+k; j++) {
      if (j < n) dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
    }
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

