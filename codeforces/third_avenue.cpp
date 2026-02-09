// https://atcoder.jp/contests/abc184/tasks/abc184_e
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

// U D L R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

vector<pair<int, int>> portals[26];
pair<int, int> start, target;
int dist[2005][2005];
bool visited[2005][2005];

void solve() {
  int row, col; cin >> row >> col;
  vector<vector<char>> grid(row, vector<char>(col, 0));

  for (int i=0; i < row; i++) {
    string s; cin >> s;
    for (int j=0; j < col; j++) {
      grid[i][j] = s[j];
      dist[i][j] = INT_MAX;

      if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
        portals[s[j] - 'a'].push_back({i, j});
      } else if (s[j] == 'S')  {
        start = {i, j};
      } else if (s[j] == 'G')  {
        target = {i, j};
      }
    }
  }

  queue<pair<int, int>> q;
  q.push(start);
  dist[start.first][start.second] = 0;
  bool found = false;
  while (!q.empty() && !found) {
    auto [r, c] = q.front(); q.pop();
    if (visited[r][c]) continue;
    visited[r][c] = 1;

    // if we are on portal, teleport
    char curr = grid[r][c];
    if (curr >= 'a' && curr <= 'z') {
      int idx = curr - 'a';
      if (!portals[idx].empty()) {
        for (pair<int, int> p: portals[idx]) {
          dist[p.first][p.second] = min(dist[p.first][p.second] , dist[r][c] + 1);
          q.push(p);
        }
        portals[idx].clear();
      }
    }

    // else discover
    for (int i=0; i < 4; i++) {
      int nr = r + dr[i], nc = c + dc[i];
      bool inside_grid = (nr >= 0 && nc >= 0) && (nr < row && nc < col);
      if (inside_grid && grid[nr][nc] != '#') {
        dist[nr][nc] = min(dist[nr][nc], dist[r][c] + 1);
        if (grid[nr][nc] == 'G'){ // target
          found = true;
          break;
        } else {
          q.push({nr, nc});
        }
      }
    }
  }

  if (!found) {
    cout << "-1\n";
    return;
  }

  cout << dist[target.first][target.second] << "\n";
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

