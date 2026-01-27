#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return; 
  }

  if (n == 2 || n == 3) {
    cout << "NO SOLUTION\n";
    return;
  }

  for (int i=2; i <= n; i+=2) {
    cout << i << " ";
  }
  for (int i=1; i <= n; i+=2) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}


// SHIT SHOW:
  // int start=2;
  // int diff = 2;
  //
  // for (int i=0; i < n; i++) {
  //   cout << start << " ";
  //   if (start + diff > n) {
  //     diff = -(2 * (i + 1) - 1);
  //   }
  //   start += diff;
  //   diff = 2;
  // }
  //
  // cout << "\n";
