#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

//max - min = gcd(max, min)
// gcd([1, m]) = 1
// at max subarr len = 2
void solve() {
  int n; cin >> n;
  if (n < 2) {
    cout << 0 << "\n";
    return;
  }

  vector<int> arr(n);
  for (int i=0; i < n; i++) cin >> arr[i];

  int ans = 0;
  for (int i=1; i < n; i++) {
  //   if (max(arr[i-1], arr[i]) == arr[i] && gcd(arr[i-1], arr[i]) == arr[i] - arr[i-1]) {
  //     ans++;
  //   }
    if (abs(arr[i] - arr[i-1]) == gcd(arr[i-1], arr[i])) ans++;
  }
  cout << ans << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}
