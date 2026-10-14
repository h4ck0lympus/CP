#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n; 
  vector<int> a(n);
  int mx = -1;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  set<int> s;
  for (int i=0; i < n; i++) s.insert(a[i]);
  int mex = 0;
  while (s.find(mex) != s.end()) {
    mex++;
  }
  // mex^2 + (n-mex)(mex+mx)
  cout << mex * mex + (n-mex) * (mex + mx) << "\n";
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

