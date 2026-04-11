#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> x(n);
  int mx = 0, mn = INF; // possibility of all sum of coins = [mn, mx]
  for (int i=0; i < n; i++) {
    cin >> x[i];
    mx += x[i];
    mn = min(mn, x[i]);
  }
  set<int> res;
  vector<bool> dp(mx+1, 0); // dp[i] = sum i possible or not
  dp[0] = 1; // sum of 0 is possible if we don't pick any coins

  int cnt = 0;
  for (int c: x) {
    for (int sum=mx; sum >= mn; sum--) {
      if (sum >= c && dp[sum-c]) {
        if (!dp[sum]) cnt++; // if marking for first time
        dp[sum] = 1;
      }
    }
  }

  cout << cnt << "\n";
  for (int i=1; i <= mx; i++) {
    if (dp[i]) cout << i << " \n"[i == mx];
  }
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

