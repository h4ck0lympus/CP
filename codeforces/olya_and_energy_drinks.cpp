#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

int dist[1005][1005];
bool visited[1005][1005];
void solve() {
  int row, col, k; cin >> row >> col >> k;
  vector<vector<char>> grid(row, vector<char>(col, 0));
  for (int i=0; i < row; i++) {
    string s; cin >> s;
    for (int j=0; j < col; j++) {
      grid[i][j] = s[j];
      dist[i][j] = INF;
    }
  }

  pair<int, int> start, target;
  cin >> start.first >> start.second;
  cin >> target.first >> target.second;
  --start.first; --start.second;
  --target.first; --target.second;

  if (start == target){
    cout << "0\n";
    return;
  }

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  queue<pair<int, int>> q;
  q.push(start);
  bool reached = false;
  dist[start.first][start.second] = 0;

  auto inside_map = [row, col](int r, int c) {
      return (r >= 0 && r <= row - 1) && (c >= 0 && c <= col - 1);
  };

  // O(n * m * k) == O(1e9) (So TLE)
  // but pruning will imporove this
  while (!q.empty() && !reached) {
    auto [r, c] = q.front(); q.pop();
    if (visited[r][c]) continue;
    visited[r][c] = 1;

    for (int i=0; i < 4; i++) {
      int nr = r, nc = c;
      int explored_cells = k;
      int time_taken = dist[r][c] + 1;

      while (explored_cells--) {
        nr += dr[i], nc += dc[i];
        if (!inside_map(nr, nc) || grid[nr][nc] == '#') break;
       // THIS IS IMPORTANT - we only explore further if we know we are on the path 
       // that is possibly better and is not explored yet
        if (dist[nr][nc] < time_taken) break;
        dist[nr][nc] = time_taken;
        q.push({nr,nc}); // keep exploring in same direction until we hit a wall or reach end
        if (nr == target.first && nc == target.second) {
          reached = true;
          break;
        }
      }
    }
  }

  if (!reached) {
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

