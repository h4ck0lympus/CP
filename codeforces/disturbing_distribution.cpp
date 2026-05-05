#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
// const int MOD = (int) (1e9 + 7);
const int MOD = (int) 676767677;

void solve() {
  int n; cin >> n; vector<int> arr(n);
  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = 0, idx = -1;
  for (int i=0; i < n; i++) {
    if (arr[i] > 1) {
      ans = (ans + arr[i]) % MOD;
      idx = i;
    }
  }
  if (idx == -1) {
    ans = 1;
  } else {
    bool one = false;
    for (int i=idx+1; i < n; i++) {
      if (arr[i] == 1) one = true;
    }
    if (one) ans = (ans + 1) % MOD;
  }
  // ans = (ans % MOD) + (c % MOD);
  cout << ans % MOD << "\n";
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

