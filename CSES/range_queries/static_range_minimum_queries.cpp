#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;

void solve() {
  int n,q; cin >> n >> q;
  vector<int> arr(n, 0);

  for (int i=0; i < n; i++) { 
    cin >> arr[i];
  }

  int log2_n = (int) log2(n);
  vector<int> m[log2_n]; // sparse tree
                         
  for (int j=1; j <= log2_n; j++) {
    int inc = 1 << j;
    for (int i=0; i + inc - 1 < n - inc; i++) {
      m[i][j] = min(m[i][j-1], m[i+(inc)])
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


// ATTEMPT-1 (Failed)
// void solve() {
//   int n,q; cin >> n >> q;
//   vector<int> arr(n+1, 0);
//   vector<int> min_arr(n+1, 0);
//
//   for (int i=1; i <= n; i++) {
//     cin >> arr[i];
//   }
//
//   int min_now = INT_MAX;
//   for (int i=1; i <= n; i++) {
//     min_now = min(min_now, arr[i]);
//     min_arr[i] = min_now;
//   }
//
//   while (q--) {
//     int a, b; cin >> a >> b;
//     cout << ((a == b) ? arr[a] : min(min_arr[a], min_arr[b])) << "\n";
//   }
// }
//
