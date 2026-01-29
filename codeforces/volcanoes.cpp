#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int n, m; cin >> n >> m; // he needs to travel to cell n, n
  if ((n*n) / 2 <= m) {
    cout << "-1\n"; 
    return;
  }
  cout << 2 * n - 2 << "\n";
}

#ifdef int
#undef int
#endif
int main() {
  solve();
}
