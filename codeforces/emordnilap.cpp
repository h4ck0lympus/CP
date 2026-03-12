#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

int fact[(int)1e5 + 10];

void _fact(int n) {
  fact[0] = 1LL;
  for (int i=1; i <= n; i++) {
    fact[i] = (fact[i-1] * i) % MOD;
  }
}

void solve(int n) {
  
  // inv(reverse(p)) = nC2 - inv(p)
  int ans = fact[n];

  ans = (ans * (n % MOD)) % MOD;
  ans = (ans * ((n-1) % MOD)) % MOD;
  cout << ans << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  vector<int> tt(t);

  int mx = INT_MIN;
  for (int i=0; i < t; i++) {
    cin >> tt[i];
    mx = max(mx, tt[i]);
  }
  _fact(mx);
  for (int n: tt) {
    solve(n);
  }
  // while (t--) solve();
#else
  solve();
#endif
}

  // n! * (n-1)
