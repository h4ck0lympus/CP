#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
  vector<int> x, mn, mx;
  DSU(int n) {
    x.resize(n, -1);
    mn.resize(n);
    mx.resize(n);
    for (int i=0; i < n; i++) {
      mn[i] = i;
      mx[i] = i;
    }
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int find(int u) {
    if (x[u] < 0) return u;
    x[u] = find(x[u]);
    return x[u];
  }
  int size(int u) {
    return -x[find(u)];
  }
  bool join(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return false;
    if (size(p1) > size(p2)) swap(p1, p2);
    x[p2] += x[p1];
    x[p1] = p2; // connect smaller to bigger
    mn[p2] = min(mn[p1], mn[p2]);
    mx[p2] = max(mx[p1], mx[p2]);
    return true;
  }
  int getMin(int u) { return mn[find(u)]; }
  int getMax(int u) { return mx[find(u)]; }
};

void solve() {
  int n, m; cin >> n >> m;
  DSU dsu(n);
  for (int i=0; i < m; i++) {
    string op;
    cin >> op;
    int u, v;
    if (op == "union") {
      cin >> u >> v;
      --u; --v;
      dsu.join(u, v);
    } else if (op == "get") {
      cin >> u;
      --u;
      cout << dsu.getMin(u)+1 << " " << dsu.getMax(u)+1 << " " << dsu.size(u) << "\n";
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

