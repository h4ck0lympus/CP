#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

void solve() {
  int x; cin >> x;

  if (x % 9 != 0) {
    cout << "0\n";
    return;
  }

  auto dy = [](int n) {
    int s = 0;
    while (n) {
      s += (n % 10);
      n/=10;
    }
    return s;
  };

  int ans = -1;
  for (int i= x; i <= x + 90; i++) { // 90 because sum of n can be max 90
    if (i - dy(i) == x) {
      ans = i;
      break;
    }
  }

  // for cases like 90
  if (ans == -1) {
    cout << "0\n";
    return;
  }

  cout << "10\n";
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

