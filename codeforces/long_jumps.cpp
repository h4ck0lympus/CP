#include "bits/stdc++.h"

using namespace std;

#define int long long
#define have_testcases 1

void solve() {
  int n; cin >> n; vector<int> arr;
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  vector<int> dp(n+1, 0);
  int ans = 0;

  for (int i=n-1; i >= 0; i--) {
    int x = i + arr[i];
    if (x <= n) dp[i] = arr[i] + dp[x];
    else dp[i] = arr[i];
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if have_testcases
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

