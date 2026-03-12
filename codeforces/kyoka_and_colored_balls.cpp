#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

int fact[(int)1e5 + 10];
int invfact[(int)1e5 + 10];

int mod_pow(int a, int e) {
  int r = 1;
  a %= MOD;
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}

int nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (((fact[n] * invfact[r]) % MOD) * (invfact[n - r] % MOD)) % MOD;
}

void solve() {
  int n; cin >> n;
  vector<int> c(n+1);
  int total =0;
  for (int i=1; i <= n; i++) {
    cin >> c[i];
    total += c[i];
  }

  fact[0] = 1;
  for (int i=1; i <= total; i++) {
    fact[i] = (fact[i-1] * i) % MOD;
  }

  invfact[total] = mod_pow(fact[total], MOD - 2);
  for (int i = total; i >= 1; i--)  {
    invfact[i - 1] = (invfact[i] * i) % MOD;
  }

  int dp = 1;
  int L = c[1]; // balls used so far
  for (int i = 2; i <= n; i++) {
    int ci = c[i];
    dp = (dp * nCr(L + ci - 1, L)) % MOD;
    L += ci;
  }

  cout << dp % MOD << "\n";
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
