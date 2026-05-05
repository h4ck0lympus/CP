#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i=0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  for (int i=0; i < n-1; i++) {
    if (a[i] == a[i+1]) {
      cout << -1 << "\n";
      return;
    }
  }
  
  for (int i=n-1; i >= 0; i--) cout << a[i] << " ";
  cout << "\n";
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

