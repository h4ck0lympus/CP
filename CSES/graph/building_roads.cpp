#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> rep; // representative cities from each island of connected graphs
vector<int> adj[100005];
bool visited[100005];

void dfs(int v) {
  visited[v] = 1;

  for (int e: adj[v]) {
    if (visited[e]) continue;
    visited[e] = 1;
    dfs(e);
  }
}

void solve() {
  int n, m;  cin >> n >> m;
  
  for (int i=0; i < m; i++) {
    int a, b; cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=0; i < n; i++) {
    if (visited[i]) continue;
    dfs(i);
    rep.push_back(i);
  }

  cout << rep.size() - 1 << "\n";
  for (int i=0; i < rep.size()-1; i++) {
    cout << rep[i] + 1 << " " << rep[i+1] + 1 << "\n"; 
  }

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

