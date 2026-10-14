#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  string a,b; cin >> a >> b;
  int x=0, y=0; 
  for (int i=0; i < n; i++) {
    if (a[i] == '(' && b[i] == '(') {
      x++; y++;
    } else if (a[i] == ')' && b[i] == ')') {
      x--; y--;
    } else if (x <= y) {
      x++; y--;
    } else {
      x--; y++;
    }

    if (x < 0 || y < 0) {
      cout << "no\n";
      return;
    } 
  }

  cout << ((x == 0 && y == 0) ? "yes" : "no") << "\n";
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

