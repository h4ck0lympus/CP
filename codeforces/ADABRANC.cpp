#include "bits/stdc++.h"

using namespace std;

// https://www.spoj.com/problems/ADABRANC/

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
  vector<int> e;
  DSU(int n) {e.resize(n+1, -1);}
  int find(int u) {
    if (e[u] < 0) return u;
    e[u] = find(e[u]);
    return e[u];
  }
  bool same(int u, int v) {
    return find(u) == find(v);
  }
  int size(int u) {
    return -e[find(u)];
  }
  void join(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    if (size(pu) > size(pv)) swap(pu, pv);
    e[pv] += e[pu];
    e[pu] = pv;
  }
};

typedef struct {
  int u, v, weight;
} Edge;

void solve() {
  int n, m, q; cin >> n >> m >> q;
  vector<Edge> edges;
  for (int i=0; i < m; i++) {
    int a,b,xi; cin >> a >> b >> xi;
    edges.push_back({a, b, xi});
  }
  sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
      return a.weight > b.weight;
  });

  typedef struct {
    int a, y, idx;
  } query;

  vector<query> qr;
  
  for (int i=0; i < q; i++) {
    int a,y; cin >> a >> y;
    qr.push_back({a, y, i});
  }

  sort(qr.begin(), qr.end(), [](const query& p1, const query& p2){
      return p1.y > p2.y;
  });
  DSU dsu(n+1);
  int x = 0;
  vector<int> ans(q);
  for (auto [st, wt, idx]: qr) {
    while (x < m && wt <= edges[x].weight) {
      dsu.join(edges[x].u, edges[x].v);
      x++;
    }
    ans[idx] = dsu.size(st);
  }
  for (int a: ans) cout << a << "\n";
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

