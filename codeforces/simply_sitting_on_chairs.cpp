#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> arr(n+1); 
  for (int i=1; i <= n; i++) {
    cin >> arr[i];
  }

  // for ith chair to be marked before it is reached, any element at idx [1, i] must be equal to i

  int ans = 0;
  map<int, int> mp;
  for (int i=1; i <= n; i++) {
    if (mp[arr[i]]) break;

    if (arr[i] <= i) {
      ans++;
      mp[arr[i]] = 1; // mark
    }
    // else skip
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

