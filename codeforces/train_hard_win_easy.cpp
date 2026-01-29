#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int n, m; cin >> n >> m;

  vector<int> first, second;

  // first and second problem score for ith participant
  for (int i=0; i < n; i++) {
    int x, y; cin >> x >> y;
    first.push_back(x);
    second.push_back(y);
  }

  // pairs who dont want to write together
  for (int i=0; i < m; i++) {

  }
}

#ifdef int
#undef int
#endif
int main() {
  solve();
}
