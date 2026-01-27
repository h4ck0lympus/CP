#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

// traaverse all the nodes of graph
// if nodes connected pick the minimum of them
// if not connected add whatever the node value

vector<int> edges[(int)1e5 + 5]; // adjaceny list
bool vis[(int)1e5 + 5];

int dfs(vector<int> &gold, int node) {
  int mn = gold[node];
  vis[node] = 1;
  // cout << "visited: " << node << "\n";

  // for each edge connected to the node
  for (int e : edges[node]) {
    if (!vis[e]) mn = min(mn, dfs(gold, e));
  }

  return mn;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> gold;
  for (int i = 0; i < n; i++) {
    int ci; cin >> ci;
    gold.push_back(ci); // amt of gold ith char asks
  }

  for (int i = 0; i < m; i++) {
    int xi, yi;
    cin >> xi >> yi;
    xi--; yi--; // 1 indexing to 0 indexing
    edges[xi].push_back(yi);
    edges[yi].push_back(xi);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    // if starting node is not visited then do dfs
    if (!vis[i]) ans += dfs(gold, i);
  }

  cout << ans << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--)
    solve();
#else
  solve();
#endif
}
