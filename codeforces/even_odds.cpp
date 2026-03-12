#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

void solve() {
  int k, n; cin >> k >> n;
  --k; --n;
  // mid will have last odd
  int mid = (int) ceil(k/2);
  
  if (mid < n) {
    cout << 2 * (n-mid) << "\n";
  } else {
    cout << 2 * n + 1 << "\n";
  }
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

