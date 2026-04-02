#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  
  for (int i=1; i <= n; i++) {
    int sz = i * i;
    int total_poss = (sz * (sz-1)) / 2; // nC2
    int attack_poss = 0;
    attack_poss += 8 * (i - 4) * (i - 4);
    attack_poss += 6 * (i-4) * 4;
    attack_poss += 4 * (i-3) * 4;
    attack_poss += 3 * 8;
    attack_poss += 2 * 4;
    attack_poss /= 2;
    cout << (total_poss - attack_poss) << "\n";
  }
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

