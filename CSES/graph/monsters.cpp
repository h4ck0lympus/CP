#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<vector<char>> game;
pair<int, int> player;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

char parent[1005][1005];

void solve() {
  int row, col; cin >> row >> col;

  queue<pair<int,int>> q;

  vector<vector<int>> distM(row, vector<int>(col, INT_MAX));
  vector<vector<int>> distP(row, vector<int>(col, INT_MAX));
  for (int i=0; i < row; i++) {
    string x; cin >> x;
    vector<char> r;
    for (int j=0; j < col; j++) {
      r.push_back(x[j]);
      if (x[j] == 'A') {
        player = {i, j};
      }
      if (x[j] == 'M') {
        q.push({i, j});
        distM[i][j] = 0;
      }
    }
    game.push_back(r);
  }

  if ((player.first == 0 || player.first == row-1) && 
      (player.second == 0 || player.second == col - 1)) {
    cout << "YES\n";
    cout << "0\n";
    return;
  }

  bool visited[1005][1005] = {0};
  while (!q.empty()) {
    // bfs from EACH monster location to EACH location on map

    auto [curr_x, curr_y] = q.front();
    q.pop();
    visited[curr_x][curr_y] = 1;

    for (int i=0; i < 4; i++) {
      int x = curr_x + dx[i];
      int y = curr_y + dy[i];
      bool is_bounded = ((x >= 0 && x < row) && (y >= 0 && y < col));
      if (is_bounded && !visited[x][y] && game[x][y] != '#') {
        visited[x][y] = 1;
        distM[x][y] = min(distM[x][y], distM[curr_x][curr_y] + 1);
        q.push({x, y});
      }
    }
  }

  memset(visited, 0, sizeof(visited));
  q.push(player);
  distP[player.first][player.second] = 0;

  bool reached_exit = false;

  pair<int, int> exit;
  while (!q.empty()) {
    auto [curr_x, curr_y] = q.front();
    q.pop();
    visited[curr_x][curr_y] = 1;

    if ((curr_x == 0 || curr_x == row - 1)&& game[curr_x][curr_y] == '.')  {
      exit = {curr_x, curr_y};
      reached_exit = true;
      break;
    }

    if ((curr_y == 0 || curr_y == col - 1)&& game[curr_x][curr_y] == '.') {
      exit = {curr_x, curr_y};
      reached_exit = true;
      break;
    }

    for (int i=0; i < 4; i++) {
      int x = curr_x + dx[i];
      int y = curr_y + dy[i];
      bool is_bounded = ((x >= 0 && x < row) && (y >= 0 && y < col));
      if (is_bounded && !visited[x][y] && game[x][y] != '#' && distP[curr_x][curr_y] + 1 < distM[x][y]) {
        distP[x][y] = distP[curr_x][curr_y] + 1;
        visited[x][y] = 1;
        q.push({x, y});
        parent[x][y] = dir[i];
      }
    }
  }

  if (!reached_exit) {
    cout << "NO\n";
    return;
  }

  string path = "";
  int r = exit.first , c = exit.second;

  while (!(r == player.first && c == player.second)) {
    char move = parent[r][c];
    if (move == 'U') r++;
    else if (move == 'D') r--;
    else if (move == 'R') c--;
    else if (move == 'L') c++;
    path += move;
  }

  reverse(path.begin(), path.end());
  cout << "YES\n";
  cout << path.size() << "\n";
  cout << path << "\n";
  return;

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

/*
 * Initial idea: 
 * find the distance from start to all the exits and from monsters to all the distance. If the shortest path from start to any exit is > shortest distance from any monster to exit then we can conclude that monster and player will collide.
 *
 * BUT obviously this is too slow and will TLE 
 *
 * so instead of "monster to exit" strategy we think about "monster to any cell(x,y)" strategy.
 */ 
