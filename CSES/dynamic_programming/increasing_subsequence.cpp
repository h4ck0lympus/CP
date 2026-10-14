#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n, 1); // dp[i] = length of lcs till idx i
  
  for (int i=1; i < n; i++) {
    // this will TLE because O(n*n)
    for (int j=i-1; j >= 0; j--) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i=0; i < n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
}


void solve_tle() {
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n, 1); // dp[i] = length of lcs till idx i
  
  for (int i=1; i < n; i++) {
    // this will TLE because O(n*n)
    for (int j=i-1; j >= 0; j--) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i=0; i < n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
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

