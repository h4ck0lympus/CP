#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

int dr[4] = {-1, +1, 0, 0};
int dc[4] = {0, 0, -1, +1};

void bfs(vector<vector<char>>& mp, int r, int c){
  int row = mp.size();
  int col = mp[0].size();

  queue<pair<int, int>> q;
  q.push({r, c});
  mp[r][c] = '*'; // mark as visited

  while (!q.empty()) {
    auto [cr, cc] = q.front();
    q.pop();

    for (int i=0; i < 4; i++) {
      int crr = cr + dr[i], ccc = cc + dc[i];
      if (crr >= 0 && crr < row && ccc >= 0 && ccc < col)  {
        if (mp[crr][ccc] == '.') {
          mp[crr][ccc] = '*';
          q.push({crr, ccc});
        }
      }
    }
  }
}

  // while (!q.empty()) {
  //   pair<int, int> curr = q.front();
  //   int cr = curr.first, cc = curr.second;
  //   q.pop();
  //
  //   if (cr != 0 && mp[cr-1][cc] == '.') {
  //     // up
  //     mp[cr-1][cc] = '*'; // mark visited
  //     q.push({cr-1, cc});
  //   }
  //
  //   if (cr != row - 1 && mp[cr+1][cc] == '.') {
  //     // down
  //     mp[cr+1][cc] = '*'; // mark visited
  //     q.push({cr+1, cc});
  //   }
  //
  //   if (cc != 0 && mp[cr][cc-1] == '.')  {
  //     // left
  //     mp[cr][cc-1] = '*';
  //     q.push({cr, cc-1});
  //   }
  //
  //   if (cc != col - 1 && mp[cr][cc+1] == '.')  {
  //     // right
  //     mp[cr][cc+1] = '*';
  //     q.push({cr, cc+1});
  //   }
  // }
  
void solve() {
  // up and left
  int row, col; cin >> row >> col;
  vector<vector<char>> mp(row, vector<char>(col, 0)); // using * for visited rooms

  int ans = 0;

  for (int r=0; r < row; r++) {
    string s; cin >> s;
    for (int c=0; c < col; c++) {
      mp[r][c] = s[c];
    }
  }

  for (int r=0; r < row; r++) {
    for (int c=0; c < col; c++) {
      if (mp[r][c] == '.') {
        bfs(mp, r, c);
        ans++;
      }
    }
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


