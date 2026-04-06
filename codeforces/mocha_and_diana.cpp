#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

struct DSU {
	vector<int> e;
	DSU(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve() {
  int n, m1, m2; cin >> n >> m1 >> m2;

  DSU d1(n), d2(n);

  for (int i=0; i < m1; i++) {
    int u, v; cin >> u >> v;
    --u; --v;
    d1.join(u, v);
  }
  for (int i=0; i < m2; i++) {
    int u, v; cin >> u >> v;
    --u; --v;
    d2.join(u, v);
  }

  vector<pair<int, int>> ans;

  for (int i=0; i < n; i++) {
    if (!d1.sameSet(0, i) && !d2.sameSet(0, i)) {
      ans.push_back({0, i});
      d1.join(0, i);
      d2.join(0, i);
    }
  }

  vector<int> a, b;

  for (int i = 0; i < n; i++) {
    if (!d1.sameSet(0, i)) a.push_back(i);
    if (!d2.sameSet(0, i)) b.push_back(i);
  }

  int i=0, j=0;

  while (i < a.size() && j < b.size()) {
    while (i < a.size() && d1.sameSet(0,a[i])) i++;
    while (j < b.size() && d2.sameSet(0,b[j])) j++;

    if (i >= a.size() || j >= b.size()) break;

    int u = a[i];
    int v = b[j];

    if (!d1.sameSet(u, v) && !d2.sameSet(u, v)) {
      ans.push_back({u, v});
      d1.join(u, v);
      d2.join(u, v);
    }
    i++; j++;
  }

  cout << ans.size() << "\n";
  for (auto [u, v]: ans) {
    cout << u + 1 << " " << v + 1 << "\n";
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

