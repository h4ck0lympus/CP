#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
  vector<int> e;
  vector<int> points;
  vector<int> neg;
  DSU(int n) { 
    e.resize(n+1, -1); 
    points.resize(n+1, 0);
    neg.resize(n+1, 0);
  }
  int find(int u) {
    if (e[u] < 0) return u;
    else return find(e[u]);
  }
  void join(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return;
    if (e[p1] > e[p2]) swap(p1, p2);
    e[p2] += e[p1];
    points[p1] -= points[p2];
    e[p1] = p2;
  }
  int get(int u) {
    int p = find(u);
    if (u == p) return points[p];
    return points[p]+points[u];
  }
  void add(int x, int v) {
    points[find(x)] += v;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  DSU dsu(n);
  for (int i=0; i < m; i++) {
    string op; cin >> op;
    if (op == "join") {
      int x,y; cin >> x >> y;
      dsu.join(x, y);
    } else if (op == "add") {
      int x,y; cin >> x >> y;
      dsu.add(x, y);
    } else if (op == "get") {
      int x; cin >> x;
      cout << dsu.get(x) << "\n";
    } else {
      assert(false);
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

