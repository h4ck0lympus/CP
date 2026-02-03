#include "bits/stdc++.h"

using namespace std;

#define int long long
#define have_testcases 0

// void s(int start, int target, int ans) {
//   if (start == target) {
//     cout << ans << "\n";
//     return;
//   }
//
//   if (start >= 1) {
//     s(start * 2, target, ans+1);
//     s(start - 1, target, ans+1);
//   } 
//
//   return;
// }

void solve() {
  int n, m; cin >> n >> m;
  int ans = 0;

  // moving backward
  while (n < m && m > 0) {
    if (m % 2 == 0) {
      m /= 2;
    } else {
      m++;
    }
    ans++;
  }

  // cout << n << " " << m << "\n";
  ans += (n - m);
  cout << ans << "\n";
  return;
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if have_testcases
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

