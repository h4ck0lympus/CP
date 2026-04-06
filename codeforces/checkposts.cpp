#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

vector<int> adj[100005];
vector<int> rev[100005];
vector<bool> vis;
vector<int> order;

void dfs1(int u) {
  vis[u] = 1;
  for (int v: adj[u]) {
    if (!vis[v]) dfs1(v);
  }
  order.push_back(u);
}

void dfs2(int u, vector<int>& comp) {
  vis[u] = 1;
  comp.push_back(u);

  for (int v : rev[u]) {
    if (!vis[v]) dfs2(v, comp);
  }
}

void solve() {
  int n; cin >> n;
  vis.resize(n);

  vector<int> c(n);
  for (int i=0; i < n; i++) {
    cin >> c[i];
  }
  int m; cin >> m;
  for (int i=0; i < m; i++) {
    int u, v; cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }

  for (int i=0; i < n; i++) {
    if (!vis[i]) dfs1(i);
  }

  fill(vis.begin(), vis.end(), 0);
  int total_cost = 0;
  int ways = 1;
  reverse(order.begin(), order.end());

  for (int u: order) {
    if (vis[u]) continue;
    vector<int> comp;
    dfs2(u, comp);
    int mn = INF;
    int cnt = 0;
    for (int node: comp) {
      mn = min(mn, c[node]);
    }

    for (int x: comp) {
      if (c[x] == mn) cnt++;
    }

    total_cost += mn;
    ways = (ways * cnt) % MOD;
  }

  cout << total_cost << " " << ways << "\n";
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

