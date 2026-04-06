#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n,m; cin >> n >> m;
  vector<int> v(n);
  vector<pair<int, int>> adj[n];

  pair<int, int> a_min = {INF, INF}; //wt, idx

  for (int i=0; i < n; i++) {
    cin >> v[i];
    if (a_min.first > v[i]) {
      a_min.first = v[i];
      a_min.second = i;
    }
  }
  for (int i=0; i < m; i++) {
    int x,y,w; cin >> x >> y >> w;
    --x; --y;
    adj[x].push_back({w, y});
    adj[y].push_back({w, x});
  }

  for (int i=0; i < n; i++) {
    if (i == a_min.second) continue;
    adj[a_min.second].push_back({a_min.first + v[i], i});
    adj[i].push_back({a_min.first + v[i], a_min.second});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0}); // wt, idx
  
  // for (auto [wt, e]: adj[0]) pq.push({wt, e});
  
  vector<int> cost(n, INF); 
  vector<bool> visited(n);
  while (!pq.empty()) {
    auto [wt, curr] = pq.top(); pq.pop();
    if (visited[curr]) continue;
    visited[curr] = 1;
    cost[curr] = wt;
    for (auto [nwt, nei]: adj[curr]) {
      pq.push({nwt, nei});
    }
  }

  int ans = 0;
  for (int c: cost) {
    ans += c;
  }

  cout << ans << '\n';
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

