#include "bits/stdc++.h"

// Conquest (Rocky Mountain 2020)
// kattis problem link: https://open.kattis.com/problems/conquest 

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

vector<int> adj[200005];
vector<bool> visited;

void solve() {
  int n, m; cin >> n >> m;
  visited.resize(n);

  vector<int> scores(n);

  for (int i=0; i < m; i++) {
    int u, v; cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for (int i=0; i < n; i++) {
    cin >> scores[i];
  }

  int ans = scores[0];
  for (int e: adj[0]) {
    pq.push({scores[e], e});
  }

  visited[0] = 1;

  while (!pq.empty()) {
    auto [cs, curr] = pq.top();
    pq.pop();
    if (visited[curr]) continue;
    visited[curr] = 1;
    if (ans > cs) {
      ans += cs;
    } else {
      break;
    }
    for (int e: adj[curr]) {
      pq.push({scores[e], e});
    }
  }
  cout << ans << "\n";
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

