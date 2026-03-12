#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

typedef struct {
  int src, dst, wt;
} edge;

void solve() {
  int n, m; cin >> n >> m;
  vector<edge> edges(m);
  vector<int> dist(n, INF);

  for (int i=0; i < m; i++) {
    int s, d, w; cin >> s >> d >> w;
    s--; d--;
    edges[i] = {s, d, w};
  }

  dist[0] = 0;

  vector<int> parent(n, -1);
  for (int i=0; i < n; i++) {
    for (auto e: edges) {
        auto [src, dst, wt] = e;
        if (dist[dst] > dist[src] + wt) {
          parent[dst] = src;
          dist[dst] = dist[src] + wt;
        }
    }
  }

  int start = -1;
  for (auto e: edges) {
    auto [src, dst, wt] = e;
    if (dist[dst] > dist[src] + wt) {
      parent[dst] = src;
      start = dst;
      break;
    }
  }

  if (start == -1) {
    cout << "NO\n";
    return;
  }

  vector<int> cycle;
  int curr = start;
  while (true) {
    cycle.push_back(parent[curr]);
    curr = parent[curr];
    if (curr == start && cycle.size() > 1) break;
  }
  reverse(cycle.begin(), cycle.end());

  cout << "YES\n";
  cout << start << " ";
  for (int i: cycle) {
    cout << i+1 << " ";
  }
  cout <<"\n";
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

