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

void solve() {
  int n; cin >> n;
  multiset<int> arr;
  // int mn = INT_MAX, mx = INT_MIN;
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.insert(x);
    // mn = min(mn, x);
    // mx = max(mx, x);
  }
  int center= *next(arr.begin(), n / 2);
  int left = distance(arr.begin(), arr.lower_bound(center)); // values < center
  int right = distance(arr.upper_bound(center), arr.end());
  cout << max(left, right) << "\n";
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

