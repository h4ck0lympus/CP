#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

vector<int> adj[100005];

void solve() {
  int n, m; cin >> n >> m;

  // G does not contain cycles
  for (int i=0; i < m; i++) {
    int x, y; cin >> x >> y;
    --x; --y;
    adj[x].push_back(y);
  }
  vector<int> in_degree(n); // count of number of edges point into each vertex

  for (vector<int>& X_nodes: adj) {
    for (int Y_node: X_nodes) {
      in_degree[Y_node]++;
    }
  }

  vector<int> dp(n, -INF); // dp[i] = longest distance to vertex i
  
  // we can use kahn's algorithm for DAG 
  // 1. it makes sure we start from starting vertices
  // 2. it makes sure all the predecors have alredy been processed.

  vector<int> sorted;
  queue<int> starting; // set of all nodes with no incoming edges
  
  for (int i=0; i < n; i++) {
    if (in_degree[i] == 0) {
      starting.push(i);
      dp[i] = 0;
    }
  }
  
  while (!starting.empty()) {
    int curr = starting.front();
    starting.pop();
    sorted.push_back(curr);
    for (int next: adj[curr]) {
      dp[next] = max(dp[next], dp[curr] + 1);
      if (--in_degree[next] == 0) {
        starting.push(next);
      }
    }
  }

  int ans = INT_MIN;

  for (int i=0; i < n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
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

