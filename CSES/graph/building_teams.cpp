#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[100005];
bool visited[100005];
int color[100005];
bool possible = true;

void dfs(int v, int c){
  visited[v] = 1;
  color[v] = c;
  for (int e: adj[v]) {
    if (!visited[e]) {
      dfs(e, c ^ 1);
    } else {
      if (color[e] == c) {
        possible = false;
        return;
      }
    }
  }
}

// classic bipartite graph example
void solve() {
  memset(color, -1, sizeof(color));
  int n, m; cin >> n >> m;

  for (int i=0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=0; i < n; i++) {
    if (!visited[i])
      dfs(i, 0);

    if (!possible) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }

  for (int i=0; i < n; i++) {
    cout << color[i] + 1 << " ";
  }
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

