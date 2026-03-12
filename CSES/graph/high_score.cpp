#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

typedef struct {
  int src, dest, wt;
} node;

void solve() {
  int n, m; cin >> n >> m;

  int dist[n];
  for (int i=0; i < n; i++) {
    dist[i] = -INF; // set weight to -INF
  }
  vector<node> edges; // {src, dest, wt}
                        //
  for (int i=0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    --a; --b;
    edges.push_back({a, b, c});
  }

  dist[0] = 0;
  for (int i=0; i < n; i++) {
    for (auto [src, dest, wt]: edges) {
      dist[dest] = max(dist[dest], dist[src] + wt); // finding maximum possible wt
    }
  }

  cout << dist[n-1] << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

