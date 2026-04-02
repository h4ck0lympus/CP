#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n,m; cin >> n >> m;
  vector<int> adj[n];
  for (int i=0; i < m; i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> color(n, -1);
 
  queue<int> q;

  int ans = 0;
  for (int i=0; i < n; i++) {
    if (color[i] == -1) q.push(i);
    bool ok = true;
    int c1 = 0, c2 = 0;
    color[i] = 0;

    while (!q.empty()) {
      int curr = q.front(); q.pop();
      if (color[curr] == 0) c1++;
      else if (color[curr] == 1) c2++;

      for (int e: adj[curr])  {
        if (color[e] == -1) {
          color[e] = color[curr] ^ 1;
          q.push(e);
        } else if (color[e] == color[curr]) {
          ok = false;
        }
      }
    }

    if (ok) ans += max(c1, c2);
  }

  cout << ans << "\n";
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

