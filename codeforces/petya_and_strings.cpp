#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

void solve() {
  string a, b;
  cin >> a >> b;

  for (char &c : a) c = tolower(c);
  for (char &c : b) c = tolower(c);

  if (a > b) cout << 1;
  else if (a < b) cout << -1;
  else cout << 0;
  cout << "\n";
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

