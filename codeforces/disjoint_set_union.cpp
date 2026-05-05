#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
  vector<int> parent;
  vector<int> size;
  DSU(int n) { 
    parent.resize(n); 
    size.resize(n);
    for (int i=0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int find(int u) { 
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
  } 
  void join(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return;
    if (size[p1] > size[p2]) swap(p1, p2);
    size[p2] += size[p1];
    parent[p1] = p2;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  DSU dsu(n);

  for (int i=0; i < m; i++) {
    string op; int u,v;
    cin >> op >> u >> v;
    --u; --v;
    if (op == "union") {
      dsu.join(u, v);
    } else if (op == "get") {
      if (dsu.find(u) == dsu.find(v)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
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

