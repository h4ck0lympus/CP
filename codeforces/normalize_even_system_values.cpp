#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;

  vector<pair<int, int>> a(n, make_pair(0, 0));

  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    while (not (a[i].first % 2)) {
      a[i].first /= 2;
      a[i].second++;
    }
  }
  sort(a.begin(), a.end());
  int ans = 0;
  int curr = 0;
  int currA = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first != currA) {
      ans += curr;
      curr = a[i].second;
      currA = a[i].first;
    } else {
      curr = max(curr, a[i].second);
    }
  }
  cout << (ans + curr) << endl;
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

