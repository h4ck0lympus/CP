#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
  vector<int> e;
  int N; // number of components
  DSU(int n) {
    e.resize(n+1, -1);
    N = n;
  }
  int find(int u) {
    if (e[u] < 0) return u;
    e[u] = find(e[u]);
    return e[u];
  }
  int size(int u) {
    int up = find(u);
    return -e[up];
  }
  void join(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    if (size(pu) > size(pv)) swap(pu, pv);
    e[pv] += e[pu];
    e[pu] = pv;
    N--;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  DSU dsu(n);
  int mxs = 1; // size 1 components in the beginning 
  for (int i=0; i<m; i++) {
    int a,b; cin >> a >> b;
    dsu.join(a, b);

    mxs = max({mxs, dsu.size(a), dsu.size(b)});
    cout << dsu.N << " " << mxs << "\n";
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

