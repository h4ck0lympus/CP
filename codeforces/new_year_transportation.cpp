#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n, t; cin >> n >> t;

  vector<int> arr;

  for (int i=0; i<n-1; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  int cur = 1;
  while (cur < t) {
    cur = cur + arr[cur - 1];
  }

  if (cur == t) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
