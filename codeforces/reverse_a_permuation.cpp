#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int)1e18;

void solve() {
  int n; cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];

  for (int i=0; i < n; i++) {
    int expected = n - i;
    if (p[i] != expected) {
      int l = i;
      int r = i+1;
      while (r < n && p[r] != expected) r++;
      reverse(p.begin() + l, p.begin() + r + 1);
      break;
    }
  }

  for (int i=0; i < n; i++) {
    cout << p[i] << " \n"[i == n-1];
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
