#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  // total cards, # of playable cards, pos of winning card, max total cost
  int n, k, p, m; cin >> n >> k >> p >> m;
  deque<int, vector<int>> dq;

  for (int i=0; i < n; i++) {
    cin >> dq[i];
  }
 
  int ans = 0;
  bool ok = true;
  while (ok) {

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

