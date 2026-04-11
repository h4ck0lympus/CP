#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> x(n+1);
  for (int i=0; i < n; i++) cin >> x[i];
  vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[l][r] = max score attainable in range l to r for first player
  for (int i=0; i < n; i++)  dp[i][i] = x[i]; // len == 1 case (base case)
  for (int len=2; len <= n; len++) { // iterate by range length
    for (int l=0; l+len-1 < n; l++) {
      int r = l + len - 1; 
      // each player will always choose b/w first or last element
      // we assume second player always takes the best possible element in his turn
     
      int a = (l+2 <= r) ? dp[l+2][r]: 0;
      int b = (l+1 <= r-1) ? dp[l+1][r-1]: 0;
      int c = (l <= r-2) ? dp[l][r-2]: 0;

      // p1 picks first element, p2 picks best from rest and then we have to pick the best from rest
      int op1 = x[l] + min(a, b); // we will get worse possibility out of those 2 ranges, because p2 would have taken best possible for itself
      // p1 picks last element, p2 picks best from rest and then we have to pick the best from rest
      
      int op2 = x[r] + min(b, c);
      dp[l][r] = max(op1, op2);
    }
  }

  cout << dp[0][n-1] << "\n";
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


// void solve() {
//   int n; cin >> n;
//   vector<int> x(n+1);
//   for (int i=0; i < n; i++) cin >> x[i];
//   vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[l][r] = max score attainable in range l to r for first player
//   for (int i=0; i < n; i++)  dp[i][i] = x[i];
//   for (int i=0; i < n; i++) {
//     for (int j=0; j < n; j++) {
//       // each player will always choose b/w first or last element
//       // we assume second player always takes the best possible element in his turn
//      
//       int a = (i+2 < n) ? dp[i+2][j]: 0;
//       int b = (i+1 < j-1) ? dp[i+1][j-1]: 0;
//       int c = (i < j-2) ? dp[i][j-2]: 0;
//
//       // p1 picks first element, p2 picks best from rest and then we have to pick the best from rest
//       int op1 = x[i] + min(a, b); // we will get worse possibility out of those 2 ranges, because p2 would have taken best possible for itself
//       // p1 picks last element, p2 picks best from rest and then we have to pick the best from rest
//       
//       int op2 = x[j] + min(b, c);
//       dp[i][j] = max(op1, op2);
//     }
//   }
//
//   cout << dp[0][n-1] << "\n";
// }

