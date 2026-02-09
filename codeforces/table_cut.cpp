#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

void solve() {
  int row, col; cin >> row >> col;
  vector<vector<int>> grid(row, vector<int>(col, 0));

  int total_ones = 0;
  map<int, int> ones; // ones in a row
  for (int i=0; i < row; i++) {
    int o = 0;
    for (int j=0; j < col; j++) {
      int x; cin >> x;
      if (x == 1) o++;
      grid[i][j] = x;
    }
    ones[i] = o;
    total_ones += o;
  }

  // always put priority on right side
  // so fulfill requirement of right side and left side SHOULD follow

  int reqd = ceil(total_ones / 2); // reqd on right side
  int r = 0, c = 0;

  string path = "";
  while (r < row && c < col) {
    int ones_in_row = ones[r];
    if (ones_in_row >= reqd) {
      // we take the whole row
      r++;
      path += 'D';
      reqd -= ones_in_row;
    } else {
      path += 'R';
    }
  }
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

