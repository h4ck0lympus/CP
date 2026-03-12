#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);


bool ok(string s1, string s2, int d) {
  for (int j=d; j < (int) s1.length(); j++) {
    if (s1[j] != s1[j%d]) {
      return false;
    }
  }

  for (int j=d; j < (int) s2.length(); j++) {
    if (s2[j] != s2[j%d]) {
      return false;
    }
  }
  
  return true;
}

void solve() {
  string s1, s2; cin >> s1 >> s2;

  if (s1 + s2 != s2 + s1) {
    cout << "0\n";
    return;
  }
  if (s1.length() > s2.length()) {
    swap(s1, s2);
  }

  int n1 = s1.length();
  int n2 = s2.length();

  int g = __gcd(n1, n2);

  int ans = 0;
  for (int i=1; i * i <= g; i++) {
    // enumerating with divisors of gcd
    if (g % i) continue;

    if (ok(s1, s2, i)) ans++;
    int other_divisor = g / i;
    if (other_divisor != i) {
      if (ok(s1, s2, other_divisor)) ans++;
    }
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

