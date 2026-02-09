#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  int n; cin >> n; vector<int> arr;

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  int cs = arr[0], ms = arr[0];
  // int parity = (cs & 1); // odd or even
  for (int i=1; i < n; i++) {
    if (abs(arr[i] % 2) == abs(arr[i-1] % 2)) {
      // same parity
      cs = arr[i];
    } else {
      cs = max(cs + arr[i], arr[i]);
    }
    ms = max(ms, cs);
  }
  // parity ^= 1;
  cout << ms << "\n";
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

