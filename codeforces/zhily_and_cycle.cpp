#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i=0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  sort(a.begin(), a.end());
  vector<bool> vis(n);
  vector<int> par(n);

  queue<int> q;
  q.push(0);
  par[0] = -1;
  int visited = 0;
  while (!q.empty()) {
    int curr = q.front(); q.pop();
    if (vis[curr]) continue;
    vis[curr] = 1;
    visited++;
    for (int i=curr+1; i < n; i++) {
      int u = a[i];
      if (!vis[u]) {
        par[u] = curr;
        q.push(u);
      }
    }
  }
  if (visited == n) {
    cout << "YES\n";
    int c = par[n-1];
    while (c != -1) {
      cout << c+1 << " ";
      c = par[c];
    }
    cout << "\n";
  } else {
    cout << "NO\n";
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

