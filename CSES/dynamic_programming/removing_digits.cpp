#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> dp(n+1, INT_MAX);

  for (int i=0; i <= min(n, 9LL); i++) {
    dp[i] = 1;
  }

  auto get_digits = [](int num) {
    vector<int> v;
    while (num) {
      v.push_back(num % 10);
      num /= 10;
    }
    return v;
  };

  for (int i=10; i <= n; i++) {
    for (int num: get_digits(i)) {
      dp[i] = min(dp[i], dp[i - num] + 1);
    }
  }
  cout << dp[n] << "\n";
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

