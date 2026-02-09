#include "bits/stdc++.h"
#include <queue>

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

// class dijkstra
vector<pair<int, int>> adj[100005];
bool visited[100005];
void solve() {
  int n, m; cin >> n >> m;

  for (int i=0; i < m; i++) {
    int a,b,c; cin >> a >> b >> c;
    --a; --b;
    adj[a].push_back({c, b}); // weight first, then dest
  }

  vector<int> d(n, INF);
  d[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [_, curr] = pq.top(); pq.pop();
    if (visited[curr]) continue;
    visited[curr] = 1;
    for (auto [dist, dest]: adj[curr]) {
      if (d[curr] + dist < d[dest]) {
        d[dest] = d[curr] + dist;
        pq.push({d[dest], dest});
      }
    }
  }

  for (int i=0; i < n; i++) {
    cout << d[i] << " \n"[i == n-1];
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

