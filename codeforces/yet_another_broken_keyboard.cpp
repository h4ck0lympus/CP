#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<char> letters(k); 
  for (int i=0 ; i < k; i++) {
    cin >> letters[i];
  }
  vector<int> dp(n+1, 0);

  dp[0] = 0;
  for (int i=1; i <= n; i++) {
    for (int j=0; j < k; j++) {
      if (s[i-1] == letters[j]) {
        dp[i] = dp[i-1] + 1;
      }
    }
  }

  int ans = 0;
  for (int i=1; i <= n; i++) {
    ans += dp[i];
  }
  cout << ans << "\n";
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

