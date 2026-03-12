#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

void solve() {
  int x, k; cin >> x >> k;
  if (x % k != 0) {
    cout << "1\n";
    cout << x << "\n";
  } else {
    cout << "2\n";
    cout << 1 << " " << (x-1) << "\n";
  }
  return;
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

