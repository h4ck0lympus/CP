#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// codejam 2008 quals - problem A

void solve() {
  int s; cin >> s;
  vector<string> engine(s);
  for (int i=0; i < s; i++) cin >> engine[i];
  int q; cin >> q;
  vector<string> queries;
  for (int i=0; i < q; i++) cin >> queries[i];

  int i = 0, j=0; 
  while (i < )
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) {
    cout << "Case #" << t << ": ";
    solve();
  }
#else
  solve();
#endif
}

