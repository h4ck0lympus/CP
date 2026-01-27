#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int n, k; cin >> n >> k;
  vector<int> arr;
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  unordered_map<int, int> f;

  int ans = 0;
  int l = 0, r = 0;

  int d = 0;
  while (r < n) {
    if (f[arr[r]] == 0) d++; // distinct till rth point
    f[arr[r]]++; // freq map for rth element

    // just in case we have more distint elements than needed, shift l of sliding window
    while (d > k) {
      f[arr[l]]--; // update freq map as we shift window
      if (f[arr[l]] == 0) d--; 
      l++;
    }

    ans += (r - l + 1);
    r++;
  }

  cout << ans << endl;

}

#ifdef int
#undef int
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
