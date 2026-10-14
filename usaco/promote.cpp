/*
ID: vjuneja1
TASK: 
LANG: C++                 
*/
#include "bits/stdc++.h"
// #include "dbg.h"
using namespace std;

#define TASK "promote"
#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int bronze_before, bronze_after; cin >> bronze_before >> bronze_after;
  int silver_before, silver_after ; cin >> silver_before >> silver_after;
  int gold_before, gold_after ; cin >> gold_before >> gold_after;
  int plat_before, plat_after ; cin >> plat_before >> plat_after;

  int gold_to_plat = plat_after - plat_before;
  int silver_to_gold = gold_after - gold_before + gold_to_plat;
  int bronze_to_silver = silver_after - silver_before + silver_to_gold;

  cout << bronze_to_silver << "\n";
  cout << silver_to_gold << "\n";
  cout << gold_to_plat << "\n";
}

#undef int
int main() {
  freopen(TASK ".in", "r", stdin);
  freopen(TASK ".out", "w", stdout);
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

