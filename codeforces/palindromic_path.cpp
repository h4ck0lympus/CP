#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

void solve() {
  int n, m; cin >> n >> m;

  vector<string> paths(n, "");
  vector<pair<int, char>> roads[n];
  bool visited[n];

  pair<int, char> start;
  for (int i=0; i < n; i++) {
    int u, v; cin >> u >> v; --u; --v;
    char c; cin >> c;
    roads[u].push_back({v, c});
  }

  queue<pair<int, char>> q;
  
  for (int i=0; i < n; i++) {
    if (!roads[i].empty()) {
      pair<int, char> route = roads[i].front();
      q.push(route); // push the first road
      paths[i] = route.second;
    }
  }

  auto is_palindrome = [](string s) {
    int i=0, j = s.size()-1;
    while (s[i++] <= s[j--]);
    return (i > j);
  };

  int res = 0;
  while (!q.empty()) {
    auto [curr_city, name] = q.front(); q.pop();
    if (visited[curr_city]) continue;
    visited[curr_city] = 1;
    res += (int) is_palindrome(paths[curr_city]);
    for (auto e: roads[curr_city]) {
      auto [next_city, next_name] = e;
      if (visited[next_city]) continue;
      visited[next_city] = 1;
      paths[next_city] = paths[curr_city] + next_name;
      q.push({next_city, next_name});
    }
  }

  cout << res << "\n";
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

