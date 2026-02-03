#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

// up, down, right, left
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
char dir[4] = {'U', 'D', 'R', 'L'};

vector<pair<int, int>> path;

bool visited[1005][1005];
char parent_dir[1005][1005];

void bfs(vector<vector<char>>& mp, int r, int c) {
  int row = mp.size();
  int col = mp[0].size();

  queue<pair<int, int>> q;
  q.push({r, c});
  visited[r][c]= 1; // mark visited
                  
  while (!q.empty()) {
    auto [cr, cc] = q.front();
    q.pop();

    for (int i=0; i < 4; i++) {
      int crr = cr + dr[i], ccc = cc + dc[i];
      if (crr >= 0 && crr < row && ccc >= 0 && ccc < col) {
        if (mp[crr][ccc] != '#' && !visited[crr][ccc])  {
          parent_dir[crr][ccc] = dir[i];
          q.push({crr, ccc});
          visited[crr][ccc] = 1;
          path.push_back({crr, ccc}); // save path;

          if (mp[crr][ccc] == 'B')
            return;
        }
      }
    }
  }
}

// shortest path from A to B
// unweighted so we can just use bfs
void solve() {
  int row, col; cin >> row >> col;
  vector<vector<char>> mp(row, vector<char>(col, 0));

  pair<int, int> A_cord, B_cord;
  for (int r=0;r<row;r++) {
    string s; cin >> s;
    for (int c=0; c < col; c++) {
      if (s[c] == 'A')
        A_cord = {r, c};
      if (s[c] == 'B')
        B_cord = {r, c};

      mp[r][c] = s[c];
    }
  }

  // start from A
  bfs(mp, A_cord.first, A_cord.second);
  if (!visited[B_cord.first][B_cord.second]) {
    cout << "NO\n";
  } else {
    string res = "";
    pair<int,int> curr = B_cord;
    while (curr != A_cord) {
      char move = parent_dir[curr.first][curr.second];
      res += move;

      if (move == 'U') curr.first++; // if we reached using up, go down
      if (move == 'D') curr.first--; 
      if (move == 'R') curr.second--;
      if (move == 'L') curr.second++;
    }

    reverse(res.begin(), res.end());
    cout << "YES\n";
    cout << res.size() << "\n";
    cout << res << "\n";
  }

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

