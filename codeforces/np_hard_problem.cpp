#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[100005];
int visited[100005];

bool possible = true;

void dfs(int v, int c) {
  if (visited[v] != -1) return;
  visited[v] = c;

  for (int u: adj[v]){
    if (visited[u] == -1) { // if not visited - visit but with inverted color
      dfs(u, c ^ 1);
    } else if (visited[u] == c)  { // if visited but color is c
      possible = false;
      return;
    }
  }
}

void solve() {
  memset(visited, -1, sizeof(visited));
  int n, m; cin >> n >> m;
  for (int i=0; i < m; i++) {
    int x, y; cin >> x >> y;
    --x; --y; // 1 idx to 0 idx
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int i=0; i < n; i++) {
    dfs(i, 0); // possible color values = {0, 1}
    if (!possible) {
      cout << "-1\n";
      return;
    }
  }

  vector<int> a, b;
  for (int i=0; i < n; i++) {
    if (visited[i] == 0) {
      a.push_back(i+1);
    } else if (visited[i] == 1) {
      b.push_back(i+1);
    }
  }

  cout << a.size() << "\n";
  for (int i=0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";

  cout << b.size() << "\n";
  for (int i=0; i < b.size(); i++) {
    cout << b[i] << " ";
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

