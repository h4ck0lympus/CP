#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n; vector<int> a(n);
  for (int i=0; i < n; i++) cin >> a[i];
  int ans = 0;
  int ps = 0;
  for (int i=n-1; i >= 0; i--) {
    ps += a[i];
    if (ps > 0) {
      ans++;
    } else {
      ps = 0;
    }
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

