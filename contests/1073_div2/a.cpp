#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  vector<int> arr;

  int oddXor = 0, evenXor = 0;

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
    if (i & 1) {
      oddXor ^= x;
    } else {
      evenXor ^= x;
    }
  }

  sort(arr.begin(), arr.end());

  int resXor = 0;
  for (int i=0; i < n; i++) {
    if (i & 1) {
      resXor ^= arr[i];
    }
  }

  if (resXor == oddXor || resXor == evenXor) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

#ifdef int
#undef int
#endif
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
