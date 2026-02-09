#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[100005];
int visited[100005];
int color[100005];
bool bip = 1; // bipartite or not
              
int size_of_island[100005]; // size of island
int edges_of_island[100005]; // edges in island


void dfs(int v, int c, int leader, vector<int>& color_count) {
  if (visited[v]) return;

  visited[v] = 1;
  color[v] = c;

  size_of_island[leader]++;
  color_count[c]++;

  for (int e: adj[v]) {
    if (!visited[e])  {
      color_count[leader]++;
      edges_of_island[leader]++;
      dfs(e, c ^ 1, leader, color_count);
    } else if (color[e] == c) {
      bip = 0;
      return;
    }
  }
}

void solve() {
  memset(color, -1, sizeof(color));
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> leaders;
  vector<vector<int>> island_color;

  // non bipartite graph already has odd cycle 0 edges 1 way
  // if not bipartite connect with same color nodes in current island
  for (int i=0; i < n; i++) {
    vector<int> color_count = {0, 0};
    if (visited[i]) continue;
    color_count[0]++;
    dfs(i, 0, i, color_count);
    if (!bip) {
      cout << "0 1\n";
      return;
    }
    leaders.push_back(i);
    island_color.push_back(color_count);
  }

  int ways = 0;

  if (leaders.size() == 1) {
    int c1 = island_color[0][0];
    int c2 = island_color[0][1];
    ways = c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2;
    cout << "1 " << ways << "\n";
  } else {
    for (int i=0; i < leaders.size(); i++) {
      for (int j=i+1; j < leaders.size(); j++) {
        int li = leaders[i];
        int lj = leaders[j];
        ways += edges_of_island[li] * size_of_island[lj] + edges_of_island[lj] * size_of_island[li];
      }
    }
    cout << "2 " << ways << "\n";
  }
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
