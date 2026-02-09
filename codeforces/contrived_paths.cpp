#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<pair<int, int>> adj[100005];


void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> arr;

  // cost to move from vertice i to j
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  for (int i=0; i < n; i++) {
    for (int j=0; j < n; j++) {
      if (i!=j) {
        adj[i].push_back({j, arr[i] + arr[j]});
      }
    }
  }

  // edges
  for (int i=0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    --u; --v;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> b; // list b of k vertices
  for (int i=0; i < k; i++) {
    int x; cin >> x; --x;
    b.push_back(x);
  }

  for (int start: b) {
    vector<bool> visited(n, 0);
    vector<int> d(n, INT_MAX);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
      int a = pq.top().second; pq.pop();
      if (visited[a]) continue;
      visited[a] = 1;
      for (auto u: adj[a]) {
        int v = u.first, w = u.second;
        if (d[a] + w < d[v]) {
          d[v] = d[a] + w;
          pq.push({d[v], v});
        }
      }
    }

    for (int i=0; i < n; i++) {
      cout << d[i] << " ";
    }
    cout << "\n";
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

