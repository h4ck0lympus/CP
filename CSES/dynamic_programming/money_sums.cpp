#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> values(n);

  int ms = 0;
  for (int i=0; i < n; i++) {
    cin >> values[i];
    ms += values[i];
  }
 
  vector<bool> dp(ms+1, 0); // dp[i] = can we reach sum i or not
  dp[0] = 1; // sum of 0 is reachable by doing nothing ...
  // since each coin can be used once - we check based on coins
  for (int v: values) {
    for (int i=ms; i >= 0; i--) {
      if (i >= v && dp[i-v]) {
        dp[i] = 1;
      }
    }
  }

  int total = 0;
  for (int i=1; i <= ms; i++) total += dp[i];

  cout << total << "\n";
  for (int i=1; i <= ms; i++) {
    if (dp[i]) cout << i << " ";
  }
  cout << "\n";
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

