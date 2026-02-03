#include "bits/stdc++.h"
#include <queue>

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[150000];
bool visited[150000];

void solve() {
  int n, m; cin >> n >> m;

  for (int i=0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // pick a node that is unvistied
  // check if node is part of cylic graph island
  
  for (int i=0; i < n; i++) {
    queue<int> q;
    vector<int> path;
    if (!visited[i]) {
      visited[i] = 1;
      q.push(i);
      while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto u: adj[s]) {
          if (visited[u]) continue;
          visited[u] = true;
          path.push_back(u);
          q.push(u);
        }
      }
    }

    cout << "path taken by " << i << ":\n";
    for (int j=0; j < path.size(); j++) {
      cout << path[j] << " ";
    }
    cout << "\n";
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

