#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  if (n == 1 && s == "0") {
    cout << "1\n";
    return;
  }

  vector<int> pos;
  for (int i=0; i < n; i++) {
    if (s[i] == '1')
      pos.push_back(i);
  }

  if (pos.empty()) {
    cout << (n+2) / 3 << "\n"; // ceil(n/3)
    return;
  }

  int ans = pos.size();
  // left boundary
  if (pos[0] >= 2) {
    ans += (pos[0] + 2) / 3;
  }

  for (int i=1; i < pos.size(); i++) {
    // 10001
    // 2   6
    // 6 - 2
    // bbobb - only 3rd position is empty else every position is blocked
    // so for zeros in middle of 2 filled -2 since each filled seat also takes away their adjacent seat
    // usable positions: pos[i-1]+2 to pos[i]-2
    int available = (pos[i]) - (pos[i-1]-1); // zeros between them
    if (available > 2) ans += (available) / 3;
  }

  int gap = n-1-pos.back();
  if (gap > 1) {
    ans += (gap + 1) / 3;
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

