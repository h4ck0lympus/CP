#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

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

void solve() {
  // num % 5 == 0 iff ending with 0 or 5
  // num of substrigs ending at good pos = 2^n - 1
  // sum 2^n-1 % MOD
  
  string a; cin >> a;
  int n; cin >> n;

  int s = 0;
  int pow2 = 1;

  for (int i=0; i < (int) a.size(); i++) {
    if (a[i] == '0' || a[i] == '5') {
      s = (s + pow2) % MOD;
    }

    pow2 = (pow2 * 2) % MOD;
  }

  if (s == 0) {
    cout << "0\n";
    return ;
  }

  // p = 2 ^ (a.size) .... gs = 1 + p + .... p ^ (n-1)
  int p = mod_pow(2, (int)a.size());

  auto inv_mod = [](int x) {
    return mod_pow(x, MOD-2);
  };

  int gs;
  if (p == 1) {
    gs = n % MOD;
  } else {
    int numer = (mod_pow(p, n) - 1 + MOD) % MOD;
    int denom = (p - 1 + MOD)  % MOD;
    gs = (numer * inv_mod(denom)) % MOD;
  }

  cout << (s * gs) % MOD << "\n";
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

