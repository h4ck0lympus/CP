#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int row, col;
  cin >> row >> col;
  int layer_num = max(row, col);

  int max_num = layer_num * layer_num; // max number in layer
  int min_num = ((layer_num - 1) * (layer_num - 1)) + 1; // min number in layer

  if (layer_num & 1) {
    // if row is odd
    if (row == layer_num) {
      // we are in the col part
      cout << min_num + col - 1 << endl;
    } else {
      // we are in row part
      cout << max_num - row + 1 << endl;
    }
  } else {
    if (row == layer_num) {
      cout << max_num - col + 1 << endl;
    } else {
      // col part
      cout << min_num + row - 1 << endl;
    }
  }
}

#ifdef int
#undef int
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
