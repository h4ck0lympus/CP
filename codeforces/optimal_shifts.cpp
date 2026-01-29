#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

// simpler way to code BUT
// TC: O(2 * n)
// SC: O(n) - we are taking n bytes more to store the s twice
void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s += s;
  n *= 2;

  int ans = 0;
  int cnt = 0;
  for (int i=0; i < n; i++) {
    if (s[i] == '0') {
      cnt++;
    }

    if (s[i] == '1') {
      ans = max(cnt, ans);
      cnt = 0;
    }
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


// TC: O(n)
// SC: O(1)
/*
  // first_gap
  int i=0, j=n-1;
  int gap = 0, ans = 0; // ans is just max gap
  while (s[i++] == '0') gap++;
  while (s[j--] == '0') gap++;

  ans = max(ans, gap);

  gap = 0;
  while (i <= j) {
    while (s[i++] == '0') gap++;
    ans = max(ans, gap);
    gap = 0;
  }

  cout << ans << "\n";
*/
