#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

// # of users connected
vector<int> edges[(int)5e5];
bool visited[(int)5e5];

int ans[(int)5e5];
void dfs(int node) {
  // comp is basically all the elements visited by starting at element node
  // since visited members' cnt won't be counted again and it would be the same
  // as cnt of starting/leaders element since ultimately they are connected
  vector<int> comp;
  stack<int> s;
  s.push(node);
  visited[node] = 1;

  int cnt = 0;
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    comp.push_back(u);
    cnt++;
    for (int v : edges[u]) {
      if (!visited[v]) {
        visited[v] = 1;
        s.push(v);
      }
    }
  }

  // evert node in that group can visit each other
  // hence each node can visit *cnt" people
  for (int n : comp) {
    ans[n] = cnt;
  }
}

void solve() {
  int n, m; cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int k; cin >> k;
    if (k == 0) continue;
    int leader;
    cin >> leader;
    leader--; // 1 indexing to 0
    for (int j = 1; j < k; j++) {
      // users belonging to ith group
      int node;
      cin >> node;
      node--;
      edges[leader].push_back(node);
      edges[node].push_back(leader);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) dfs(i);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
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
  while (t--)
    solve();
#else
  solve();
#endif
}
