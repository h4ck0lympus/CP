#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// n is small so we can bruteforce
void solve() {
  int n; cin >> n;
  string s; cin >> s;

  int cur = 1;
  set<int> ans; // distinct people who have the ball
  ans.insert(1); // student 1 always has ball
  
  for (int i=0; i < n; i++) {
    if (cur == 1 || s[cur-1] == 'R') {
      cur++; // first to second always
    } else if (cur == n || s[cur-1] == 'L') {
      cur--; // last to secnd last alwyas
    }
    ans.insert(cur);
  }
  cout << ans.size() << "\n";
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

