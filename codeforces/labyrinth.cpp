#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

// U D L R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// vector<vector<pair<int, int>>> visited; // every cell will store the min left and min right used to reach that particular cell

int min_left[2000][2000];
int min_right[2000][2000];

typedef struct {
  int row, col, left_used, right_used;
} state;

void solve() {
  int row, col; cin >> row >> col;
  int start_r, start_c; cin >> start_r >> start_c;
  --start_r; --start_c;
  int x, y; cin >> x >> y;

  vector<vector<char>> grid(row, vector<char>(col, 0));

  for (int r=0; r < row; r++) {
    string line; cin >> line;
    for (int c=0; c < col; c++) {
      grid[r][c] = line[c];
      min_left[r][c] = INT_MAX;
      min_right[r][c] = INT_MAX;
    }
  }

  // if we go left by L times, then we can only go right R times, from that updated position, not old position

  queue<state> q;
  q.push({start_r, start_c, 0, 0});
  min_left[start_r][start_c] = 0;
  min_right[start_r][start_c] = 0;

  int possible = 0;
  while (!q.empty()) {
    auto [curr_r, curr_c, curr_left_used, curr_right_used] = q.front();
    q.pop();
    if (curr_left_used > min_left[curr_r][curr_c] || curr_right_used > min_right[curr_r][curr_c]) continue;
    for (int i=0; i < 4; i++) {
      int nr = curr_r + dr[i], nc = curr_c + dc[i];
      int new_left_used = curr_left_used, new_right_used = curr_right_used;
      if (dc[i] == -1) new_left_used++;
      if (dc[i] == 1) new_right_used++;
      bool we_can_go = (new_left_used <= x && new_right_used <= y); // follows left and right condn
      bool bounded = (nr >= 0 && nr <= row - 1) && (nc >= 0 && nc <= col -1); // is inside map
      bool is_better_left = (new_left_used < min_left[nr][nc]); // found better way for left
      bool is_better_right = (new_right_used < min_right[nr][nc]); // better way for right
      if ((is_better_left || is_better_right) && we_can_go && bounded && grid[nr][nc] == '.') {
        q.push({nr, nc, new_left_used, new_right_used});
        min_left[nr][nc] = min(min_left[nr][nc], new_left_used);
        min_right[nr][nc] = min(min_right[nr][nc], new_right_used);
      }
    }
  }

  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      if (min_right[i][j] != INT_MAX && min_left[i][j] != INT_MAX) {
        possible++;
      }
    }
  }

  cout << possible << "\n";
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

