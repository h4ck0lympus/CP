#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, x; cin >> n >> x;
  vector<int> c(n);

  vector<int> dp(n+x+1, INF); // min number of coins needed to get sum = n
  dp[0]=0; // sum =0, no coins needed, only one way

  for (int i=0; i < n; i++) {
    cin >> c[i];
    // dp[c[i]] = 1; // if n = denomination we have, only one coin needed of the denomination
  }

  // if x == one of the denominations
  // if (dp[x] != INF) {
  //   cout << dp[x] << "\n"; // 1
  //   return;
  // }

  for (int i=1; i <= x; i++) {
    for (int ci: c) {
      // pick minimum out of all possible denomiations
      if (i - ci >= 0) dp[i] = min(dp[i], dp[i-ci]+1);  // +1 because we are choosing that denomination
    }
  }
  

  cout << ((dp[x] != INF) ? dp[x]: -1) << "\n";
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

