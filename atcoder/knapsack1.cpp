#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve1() {
  int n, W; cin >> n >> W;
  vector<int> w(n), v(n);
  for (int i=0; i < n; i++) {
    cin >> w[i] >> v[i];
  }

  // dp[i][j] = max items we can get using first i items and total weight <= w
  vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

  for (int i=1; i <= n; i++) {
    for (int j=1; j <= W; j++) {
      if (w[i-1] <= j) {
        // if weight of current item < j
        // dp[i-1][j] = we don't pick the item, and weight remains the same as before
        // dp[i-1][j - w[i-1]] = pick current item, and previous item with whatever weight we have left
        // to fulfill the total requirement (total_wt - current_wt) 
        // + 
        // value of current item
        dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i-1]] + v[i-1]); // not pick or pick the item
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[n][W] << "\n";
}

// better space complexity
void solve() {
  int n, W; cin >> n >> W;
  vector<int> w(n), v(n);
  for (int i=0; i < n; i++) {
    cin >> w[i] >> v[i];
  }

  vector<int> dp(W+1, 0);

  for (int i=0; i < n; i++) {
    for (int j=W; j >= w[i]; j--) {
        dp[j] = max(dp[j], dp[j-w[i]] + v[i]); // don't take or take and use the most optimal weight for next time
    }
  }

  cout << dp[W] << "\n";
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



/*
 * initial approach
  // dp[i][0] = we do not pick ith item
  // dp[i][1] = we pick ith item
  // vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(2));

  // not pick last, pick_last
  pair<int,int> npl = {0, 0}; // if we do no pick = 0, weight used = 0
  pair<int,int> pl = {v[0], w[0]}; // we picked so bag value = v[0], weight used = w[i]

  for (int i=1; i < n; i++) {
    int cv = v[i], cw = w[i];
    pair<int, int> np, p; // not pick, pick

    if (npl.first > pl.first)  {
      np = {npl.first, npl.second};
      if (cw + npl.second <= W) p = {cv + npl.first, cw + npl.second};
    } else {
      np = {pl.first, pl.second};
      if (cw + npl.second <= W) p = {cv + pl.first, cw + pl.second};
    }

    npl = np;
    pl = p;
  }

  cout << max(npl.first, pl.first) << "\n";

*/
