#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

void solve() {
  int row, col; cin >> row >> col;
  vector<vector<int>> grid(row, vector<int>(col, 0));

  int total_ones = 0;
  for (int i=0; i < row; i++) {
    // deque<int> ones_in_row;
    for (int j=0; j < col; j++) {
      int x; cin >> x;
      if (x == 1) {
        total_ones++;
        // ones_in_row.push_back(j);
      }
      grid[i][j] = x;
    }
    // ones.push_back(ones_in_row);
  }

  // always put priority on right side
  // so fulfill requirement of right side and left side SHOULD follow

  string path = "";
  int target = (int) ceil(total_ones / 2); // reqd on right side
  int current_ones = 0;
  int c=0;
  for (int r=0; r < row; r++) {
    int num_ones = 0;
    for (int i=c; i < col; i++) if (grid[r][i] == 1) num_ones++;

    while (c < col && current_ones + num_ones > target) {
      if (grid[r][c] == 1) num_ones--;
      path+='R';
      c++;
    }

    current_ones += num_ones;
    path += 'D';
  }

  while (c < col) {
    path+='R'; c++;
  }

  cout << current_ones * (total_ones - current_ones) << "\n";
  cout << path << "\n";
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



  // while (reqd > 0 && r < row && c < col) {
  //   int ones_in_row = ones[r].size();
  //   if (ones_in_row <= reqd) {
  //     // we take the whole row
  //     r++;
  //     path += 'D';
  //     reqd -= ones_in_row;
  //   } else {
  //     int how_may_more = ones_in_row - reqd; // 1 to 0 idx
  //     if (how_may_more == ones_in_row) {
  //       // we skip all the ones in row and leave them for left part
  //       for (int i=0; i < ones_in_row+1; i++) { // +1 because we want to skip the last one as well
  //          path += 'R';
  //          c++;
  //       }
  //     }
  //   }
  // }
  //
  // while (reqd == 0 && r < row && c < col) {
  //   path += 'D'; r++;
  //   path += 'R'; c++;
  // }
  //
