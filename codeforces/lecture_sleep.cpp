#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, k; cin >> n >> k; // num of minutes, num of minutes to keep boy awake
  vector<int> a(n); // num of thereoms prof tells at ith min
  vector<int> t(n); // boy's behaviour
  
  for (int i=0; i < n; i++) {
    cin >> a[i];
  }

  int base = 0;
  for (int i=0; i < n; i++) {
    cin >> t[i];
    if (t[i]) base += a[i];
  }

  int ans = base;
  for (int i=0; i < n; i++) {
    if (t[i] == 0) {
      int s = base;
      for (int j=i; j < n && j < i+k; j++) {
        if (t[j] == 0) s += a[j];
      }
      ans = max(ans, s);
    }
  }

  cout << ans << "\n";
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

