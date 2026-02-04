#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

vector<vector<char>> game;
vector<pair<int, int>> monsters;
vector<pair<int, int>> exits;
pair<int, int> player;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool visited[100005][100005];
char parent[100005][100005];

int start_to_exit = INT_MAX;

void bfs(pair<int, int> start, pair<int, int> end) {
  int distance = 0;
  queue<pair<int, int>> q;
  q.push(start);
  
  while (!q.empty()) {
    pair<int, int> s = q.front();
    q.pop();

    for (int i=0; i < 4; i++) {
      int x = s.first + dx[i];
      int y = s.second + dy[i];
      if (game[x][y] != '#') {
        visited[x][y] = 1;
        parent[x][y] = dir[i];
        q.push({x, y});
      }
    }
  }
}

void solve() {
  int row, col; cin >> row >> col;

  for (int i=0; i < row; i++) {
    string x; cin >> x;
    vector<char> r;
    for (int j=0; j < col; j++) {
      r.push_back(x[j]);
      if (x[j] == 'A') {
        player = {i, j};
      }

      if ((i == 0 || i == row - 1)&& x[j] == '.') {
        exits.push_back({i, j});
      }

      if ((j == 0 || j == col - 1)&& x[j] == '.') {
        exits.push_back({i, j});
      }
    }
    game.push_back(r);
  }

    // find shortest path from start to exit

    // find shortest path from monster to exit

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
