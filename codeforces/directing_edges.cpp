#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

bool dfs(vector<vector<int>>& adj, vector<int>& vis, int u) {
  vis[u] = 1;
  for (int v: adj[u]) {
    if (vis[v] == 1) return true;
    if (vis[v] == 0 && dfs(adj, vis, v)) return true;
  }
  vis[u] = 2;
  return false;
}

void solve() {
  int n, m; cin >> n >> m;
  cout << n << " " << m << "\n";
  vector<vector<int>> adj(n);
  vector<int> vis(n);
  bool undir = 0, cycle = 0;

  for (int i=0; i < m; i++)  {
    int t,x,y; cin >> t >> x >> y;
    cout << t << " " << x << " " << y << "\n";
    --x; --y;
    if (t) adj[x].push_back(y);
  }

  for (int i=0; i < n; i++) {
    if (vis[i] == 0 && dfs(adj, vis, i)) {
      cycle = true;
      break; 
    }
  }
  cout << (cycle ? "NO": "YES") << "\n";
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

