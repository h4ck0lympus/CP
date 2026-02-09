#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  int n; cin >> n;
  vector<int> arr1, arr2; 

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr1.push_back(x);
    arr2.push_back(x);
  }

  sort(arr2.begin(), arr2.end());

  int ans = INT_MIN;
  bool sorted = true;
  for (int i=0; i < n; i++) {
    if (arr1[i] != arr2[i]) {
      ans = max(ans, abs(arr1[i] - arr2[i]));
      sorted = false;
    }
  }

  if (sorted) {
    cout << "-1\n";
    return;
  }

  cout << ans << "\n";
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

