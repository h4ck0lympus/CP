#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// void solve() {
//   
// }

string solve(string s, int k) {
  string t = "";
  for (int i=0; i < s.size(); i++) {
    if (s[i] == '0' && k > 0) {
      t += '1';
      k--;
    } else {
      t += '0';
    }
  }
  return t;
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

