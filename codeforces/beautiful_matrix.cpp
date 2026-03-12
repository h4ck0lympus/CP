#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

void solve() {
  int mat[5][5];
  
  int x=-1, y=-1;

  for (int i=0; i < 5; i++) {
    for (int j=0; j < 5; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 1) {
        x=i; y=j;
      }
    }
  }

  cout << abs(2-x) + abs(2-y) << "\n";
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

