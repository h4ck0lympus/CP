#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

void solve() {
  int n, w; cin >> n >> w;

  // how far i can go while removing the log
//   for (int i=0; i < n; i++) {
//     if (i % )
//   }

    cout << n - (n / w) << "\n";
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

