#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = 998244353; // (int) (1e9 + 7);

int modpow(int a, int e) {
  int p = 1;
  while (e) {
    if (e & 1) p = p * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }
  return p;
}

// beautiful iff star is MST
// MST -- non tree edge u,v (u, v) >= max edge from u to v
void solve() {
  int n, k; cin >> n >> k;
  
  // all combinations of vertices
  vector<vector<int>> C(n,vector<int>(n, 0));
  for (int i = 0; i <= n-1; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }

  vector<int> dp(n, 0); // dp[i] = ways to assign i nodes so far
  dp[0] = 1;
  for (int i=1; i <= k; i++) {
    vector<int> dp1(n, 0);
    for (int used=0; used <= n-1; used++) {
      if (!dp[used]) continue;  // not possible
      for (int cnt=0; used+cnt<= n-1; cnt++) { // num of nodes with x[u] -- all possibitliies
        int ways = C[used+cnt][cnt];
        int mx = cnt * used + cnt * (cnt - 1) / 2;
        int edge_choices = modpow(k-i+1, mx);
        int add = dp[used];
        add = add * ways % MOD;
        add = add * edge_choices % MOD;
        dp1[used+cnt] = (dp1[used+cnt] + add) % MOD;
      }
    }
    dp = dp1;
  }
  cout << dp[n-1] << "\n";
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

