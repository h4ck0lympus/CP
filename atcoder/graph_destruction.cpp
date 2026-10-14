#include "bits/stdc++.h"

// REVIEW

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
  vector<int> e;
  DSU(int n) { e.resize(n, -1);}
  int find(int u) {
    if (e[u] < 0) return u;
    e[u] = find(e[u]);
    return e[u];
  }
  int size(int u) {
    return -e[find(u)];
  }
  bool same(int u, int v) {
    return (find(u) == find(v));
  }
  void join(int u, int v) {
    int up = find(u), vp = find(v);
    if (up == vp) return;
    if (size(up) > size(vp)) swap(up, vp);
    e[vp] += e[up];
    e[up] = vp;
  }
};

void solve() {
  int n,m; cin >> n >> m;
  vector<int> adj[n+1];
  for (int i=0; i < m; i++) {
    int a,b; cin >> a >> b;
    // constraints a < b -  so we make sure that we only process the nodes 
    // that are alive while handling the nodes in reverse
    adj[a].push_back(b);
  }

  DSU dsu(n+1);
  vector<int> res = {0};
  int ans = 0;
  for (int i=n; i >= 2; i--) {
    ans++; 
    for (int e: adj[i]) {
      if (!dsu.same(i, e)) {
        dsu.join(i, e);
        ans--;
      } 
    }
    res.push_back(ans);
  }
  reverse(res.begin(), res.end());
  for (int a: res) cout << a << "\n";
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

