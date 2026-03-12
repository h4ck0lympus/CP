#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int)1e18;

void solve() {
  int y; cin >> y;

  auto f = [](int x) {
    int a[10] = {0}; // {0...9}
    while (x) {
      int last = x % 10;
      a[last]++;
      if (a[last] > 1) return false;
      x/=10;
    }
    return true;
  };

  for (int i = y + 1; i <= 9050; i++) {
    if (f(i)) {
      cout << i << "\n";
      break;
    }
  }
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--)
    solve();
#else
  solve();
#endif
}
