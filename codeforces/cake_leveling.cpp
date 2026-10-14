/*
ID: vjuneja1
TASK: 
LANG: C++                 
*/
#include "bits/stdc++.h"
// #include "dbg.h"
using namespace std;

#define TASK ""
#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// can we use median of the numbers ?? 
void solve() {
  int n; cin >> n;
  int s =0;
  int mx = INF;
  for (int i=1; i <= n; i++) {
    int x; cin >> x;
    s += x;
    mx = min(mx, s / i);
    cout << mx << " ";
  }
  cout << "\n";
}

#undef int
int main() {
  // freopen(TASK ".in", "r", stdin);
  // freopen(TASK ".out", "w", stdout);
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

