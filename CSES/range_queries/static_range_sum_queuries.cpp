#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

/*
 1 - >X1
 2 -> X1 + X2 
 3 -> X1 + X2 + X3
 4 -> X1 + X2 + X3 + X4

 [2, 4] =  X2 + X3 + X4
 => (X1 + X2 + X3 + X4) - (X1) 
 => arr[b] - arr[a-1]
*/

void solve() {
  int n, q; cin >> n >> q;
  vector<int> arr(n+1, 0);

  for (int i=1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i=1; i <= n; i++) {
    arr[i] = arr[i] + arr[i-1]; // pref sum
  }

  while (q--) {
    int a, b; cin >> a >> b;
    cout << arr[b] - arr[a-1] << "\n";
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

