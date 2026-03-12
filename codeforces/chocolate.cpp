#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n; vector<int> arr(n);
  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> pos;
  for (int i=0; i < n; i++) {
    if (arr[i] == 1) pos.push_back(i);
  }

  if (pos.empty()) {
    cout << "0\n";
    return;
  }

  if (pos.size() == 1) {
    cout << "1\n";
    return;
  }

  int ans = 1;
  for (int i=0; i < (int) pos.size()-1; i++) {
    int gap = pos[i+1] - pos[i] - 1;
    ans *= (gap + 1);
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

