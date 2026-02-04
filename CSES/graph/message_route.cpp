#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[100005];
bool visited[100005];
int parent[100005];
bool possible = false;

void bfs(int start, int target) {
  memset(parent, -1, sizeof(parent));
  vector<int> path;
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  path.push_back(start);
  parent[start] = -2;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int e: adj[v]) {
      if (visited[e]) continue;
      visited[e] = 1;
      q.push(e);
      path.push_back(e);
      parent[e] = v;
      if (e == target) possible = 1;
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;

  for (int i=0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // starting bfs from 0 
  // check if starting bfs from 0 we reach n - 1 or not

  bfs(0, n-1);
  if (!possible) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  vector<int> path;
  path.push_back(n-1);
  for (int i=n-1; i > 0; i=parent[i]) {
    path.push_back(parent[i]);
  }
  cout << path.size() << "\n";
  reverse(path.begin(), path.end());
  for (int i: path) {
    cout << i + 1 << " ";
  }
  cout << "\n";

  return;
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

