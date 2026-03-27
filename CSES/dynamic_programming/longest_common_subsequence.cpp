#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  
  for (int i=0; i < n; i++) {
    cin >> a[i];
  }

  for (int i=0; i < m; i++) {
    cin >> b[i];
  }

  // dp[i][j] = length of lcs till length i of string a and length j of string b
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for (int i=1; i <= n; i++) {
    for (int j=1; j <= m; j++) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[n][m] << "\n";

  int i=n, j=m;
  vector<int> lcs;
  while (dp[i][j] > 0) {
    if (a[i-1] == b[j-1]) {
      lcs.push_back(a[i-1]);
      i--; j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }

  auto num = lcs.end();
  while (num != lcs.begin()) {
    --num;
    cout << *num << " ";
  }
  cout << "\n";
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

