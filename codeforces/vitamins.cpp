#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;

  // total 2^3 (1 << 3) possibilities for drink
  vector<int> dp(1 << 3, INF); // dp[mask] = minimum cost to achieve mask

  dp[0] = 0;
    
  for (int i=0; i < n; i++) {
    int cost; cin >> cost;
    string vitamin; cin >> vitamin;

    int mask = 0; // mask of current drink

    // iterate for whole vitamin string to make the mask for current drink
    for (char v: vitamin) {
      int pos = v - 'A';
      mask |= (1 << pos);
    }

    // check against the mask of all drinks 
    // we may use the previously bought drink combination mask
    // or just use the current drink only
    for (int j=0; j < (1 << 3); j++) {
      dp[mask] = min(dp[mask], dp[mask] + cost); // use current drink only - check against current mask
      dp[j | mask] = min(dp[j | mask], dp[j] + cost); // use previous drink with current drink to make combination of drink
    }
  }

  // we consider all vitamins
  int ans = (dp[7] != INF) ? dp[7] : -1;
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

