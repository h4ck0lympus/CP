#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  // zeros can only be added by either 5*2 or 10
  int n; cin >> n;
  int zeros = 0;

  // but we also need to check for cases like n = 100 where 25 comes and contribute 2 zeros (25 * 4)
  // so keep iterating for each power of 5
  while (n >= 5) {
    zeros += n / 5;
    n = n / 5;
  }
  cout << zeros << endl;
}

#ifdef int
#undef int
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // int t;
  // cin >> t;
  // while (t--)
    solve();
}
