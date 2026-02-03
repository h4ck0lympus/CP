#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  int n; cin >> n;
  int l=1, r=n;
  vector<int> perm;

  while (l < r) {
    perm.push_back(l);
    perm.push_back(r);
    l++; r--;
  }
  if (l == r) {
    perm.push_back(l);
  }

  for (int i=n-1; i>=0; i--) {
    cout << perm[i] << " ";
  }
  cout << "\n";
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

