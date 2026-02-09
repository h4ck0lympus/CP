#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[150000];
bool visited[150000];

int vertices[150000]; // vertices per island stored by island leader
int edges[150000]; // edges per island stored by island leader

void dfs(int v, int leader) {
  visited[v] = 1;
  vertices[leader]++;

  for (int e: adj[v]) {
    edges[leader]++;
    if (visited[e]) continue;
    dfs(e, leader);
  }
}

// TODO: do this using dsu as well
void solve() {
  int n, m; cin >> n >> m;

  for (int i=0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=0; i < n; i++) {
    if (visited[i]) continue;
    dfs(i, i);

    int v = vertices[i];
    if (edges[i] != v * (v-1)) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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

