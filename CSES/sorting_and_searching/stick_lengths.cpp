#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n; cin >> n;
  vector<int> arr;

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  sort(arr.begin(), arr.end());

  int median = arr[(n-1) / 2];

  int ans = 0;
  for (int i=0; i < n; i++) {
    ans += abs(median - arr[i]);
  }

  cout << ans << "\n";
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

