#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  string s, t; cin >> s >> t;

  // dp[i][j] = length of lcs if considering 
  //            first i chars of string s and 
  //            first j chars of string t

  vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
  dp[0][t.size()] = 0;
  dp[s.size()][0] = 0;

  for (int i=1; i <= s.size(); i++) {
    for (int j=1; j <= t.size(); j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
     }
    }
  }

  int i = s.size(), j = t.size(); 

  string lcs = "";
  while (dp[i][j] > 0) {
    if (s[i-1] == t[j-1]) {
      lcs += s[i-1];
      i--;
      j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }

  reverse(lcs.begin(), lcs.end());
  cout << lcs << "\n";
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

