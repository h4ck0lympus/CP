#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n,m; cin >> n >> m;
  vector<int> adj[n+1];
  for (int i=0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> col(n+1, -1);
  vector<int> c1,c2;
  queue<int> q;
  q.push(1);
  col[1]=0;
  while (!q.empty()) {
    int curr = q.front(); q.pop();
    if (col[curr] == 0) c1.push_back(curr);
    else c2.push_back(curr);
    for (int e: adj[curr]) { 
      if (col[e] == -1) {
        col[e] = col[curr] ^ 1;
        q.push(e);
      }
    }
  }

  if (c1.size() > c2.size()) swap(c1, c2);

  cout << c1.size() << "\n";
  for (int x: c1) {
    cout << x << " " ;
  }
  cout << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

