#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i < n; i++) cin >> arr[i];

  vector<int> dp(n+1, 0);
  int ans = 0;

  if (arr[0]) {
    ans = 1; // if first is hard level, atleast one skip is needed
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

