#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n+1);
  for (int i=1; i <= n; i++) cin >> a[i];
  set<int> s;
  for (int i=1; i<=n; i++){
    int x = (m-((a[i] + i) % m)) % m;
    s.insert(x);
  }

  if (s.size() == m) cout << "NO\n";
  else cout << "YES\n";
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

