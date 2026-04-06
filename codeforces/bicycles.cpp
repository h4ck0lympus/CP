#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);


/*
the problem with this question is that i don't know the best cycle combination for solving this problem i.e. when we start from node 1, there is only one cycle which we have cycle s_1 , 

we can't pick the edge with minimum weight right now because what if the edge with minimum weight has the worse cycle 

for this reason typical greedy approach (djikstra) is not optimal because it considers local minima not global minima

for this reason we solve it using dp which will help us get global minima for a state
*/

void solve() {
  int n,m; cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);

  for (int i=0; i < m; i++) {
    int u,v,w; cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  vector<int> s(n);
  for (int i=0; i < n; i++) {
    cin >> s[i];
  }

  vector<vector<int>> dist(n, vector<int>(1001, INF)); // dist[i][s] = min cost to reach node i with current best min slowness = s
  
  priority_queue<tuple<int, int, int>,  vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
  dist[0][s[0]] = 0;
  pq.push({0, 0, s[0]});

  while (!pq.empty()) {
    auto [d, curr, cs] = pq.top();
    pq.pop();
    
    // if we are not coming from minimum possible bike combination, skip
    if (d != dist[curr][cs]) continue;

    for (auto[edgewt, dest]: adj[curr]) {
      int ns = min(cs, s[dest]);
      int nd = d + edgewt * cs; // we pre-caclculate the time taken to visit next city with min slowness
      if (nd < dist[dest][ns]) {
        dist[dest][ns] = nd;
        pq.push({nd, dest, ns});
      }
    }
  }

  int ans = INF;
  for (int i=0; i < 1001; i++) {
    ans = min(ans, dist[n-1][i]);
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

