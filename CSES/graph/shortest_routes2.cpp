#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

// classic floyd-warshal problem
void solve() {
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> dist(500, vector<int>(500, INF));
  
  for (int i=0; i < n; i++) dist[i][i] = 0; // distance to itself = 0

  for (int i=0; i < m; i++) {
    int a,b,c; cin >> a >> b >> c;
    --a; --b;
    dist[a][b] = min(dist[a][b], c); // distance to direct neighbour
    dist[b][a] = min(dist[b][a], c); // distance to direct neighbour
  }

  for (int i=0; i < n; i++) { // intermediate
    for (int j=0; j < n; j++) { // source
      for (int k=0; k < n; k++) { // destination
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  while (q--) {
    int a, b; cin >> a >> b;
    --a; --b;
    cout << ((dist[a][b] != INF) ? dist[a][b] : -1) << "\n";
  }
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

