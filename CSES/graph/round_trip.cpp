#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<int> adj[100005];
bool visited[100005];
int parent[100005];

bool found = false;

int start_cycle = -1, end_cycle = -1;

void dfs(int v, int p) {
  visited[v] = 1;

  for (int e: adj[v]) {
    if (e == p) continue;
    if (visited[e]) {
      found = true;
      start_cycle = e;
      end_cycle = v;
      return;
    }
    parent[e] = v;
    dfs(e, v);
    if (found) return;
  }
}

// classic "cyclic" graph check question
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
    parent[i] = -1;
    dfs(i, -1);
    if (found) break;
  }

  if (!found) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  vector<int> cyc;
  cyc.push_back(start_cycle);

  int curr = end_cycle;
  while (curr != start_cycle) {
    cyc.push_back(curr);
    curr = parent[curr];
  }
  cyc.push_back(start_cycle);

  cout << cyc.size() << "\n";
  for (int i=0; i < cyc.size(); i++) {
    cout << cyc[i] + 1 << " ";
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

