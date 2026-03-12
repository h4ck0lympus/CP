#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;

  while (n > 1) {
    if (n & 1) {
      cout << "YES\n";
      return;
    }
    n /= 2;
  }

  cout << "NO\n";

  // any number : 2 ^ n * K
  // k = 1 then even
  // k > 1 then odd
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

