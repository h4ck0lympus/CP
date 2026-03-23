#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

int maxN;
vector<int> N;

void solve() {
  int t; cin >> t;
  N.resize(t);
  for (int i=0; i < t; i++) {
    cin >> N[i];
    maxN = max(maxN, N[i]);
  }

  // dp[i][j] = num of ways to extend tower to height = i if split in between (j = 1) or not (j = 0)
  vector<vector<int>> dp(maxN+1, vector<int>(2, 0));

  // base case
  dp[1][0] = 1; // ways to extend a block to height = 1 (no vertical split)
  dp[1][1] = 1; // vertical split in between

  for (int i=2; i <= maxN; i++) {
    dp[i][0] += (2 * dp[i-1][0]) % MOD; // 2 ways - continue or not continue
    dp[i][0] += (dp[i-1][1]) % MOD; // i-1 split, we can only continue new block for j=0

    dp[i][1] += (4 * dp[i-1][1]) % MOD; // 4 ways to extend if there is split, and split in previous one as well
    dp[i][1] += dp[i-1][0] % MOD;
  }

  for (int n: N) {
    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
  }
}

void attempt1() {
  int t; cin >> t;
  N.resize(t);
  for (int i=0; i < t; i++) {
    cin >> N[i];
    maxN = max(maxN, N[i]);
  }

  vector<int> dp(maxN + 1); // dp[i] = num of ways to place block of n = i

  dp[0] = 0; // ways to put block of 2x0 = 0
  dp[1] = 2; // ways to put block of 2x1 = 2 (manually calculating)

  for (int i=2; i <= maxN; i++) {
    dp[i] = 1; // when we can just cover the whole block with 2 x i block - only one way to do that
    
    for (int j=1; j < i; j++) {
      dp[i] += ((dp[j] % MOD) * (dp[i-j] % MOD)) % MOD;
    }
  }

  for (int n: N) {
    cout << dp[n] % MOD << "\n";
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

