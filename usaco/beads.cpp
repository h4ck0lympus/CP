/*
ID: vjuneja1
TASK: beads
LANG: C++                 
*/
#include "bits/stdc++.h"

#define TASK "beads"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n; cin >> n; 
  string s; cin >> s;
  s += s;

  int red = 0;
  int blue = 0;
  int ans = 0;

  for (int i=0; i < n; i++) {
    int left = 0;
    char c = 'w';
    int l = i;
    while (l >= 0) {
      if (s[l] == c || s[l] == 'w') {
        left++;
      } else if (c == 'w') {
        c = s[l]; // change the color to whatever the first non white color is
        left++; 
      } else {
       break; 
      }
      l--;
    }

    c = 'w';
    int r = i+1;
    int right = 0;
    while (r < 2 * n) {
      if (s[r] == c || s[r] == 'w') {
        right++;
      } else if (c == 'w') {
        c = s[r];
        right++;
      } else {
       break; 
      }
      r++;
    }

    int curr_ans = right + left;
    curr_ans = min(n, curr_ans); // right + left can't be more than n
    ans = max(ans, curr_ans);
  }

  cout << ans << "\n";
}

#undef int
int main() {
  freopen(TASK ".in", "r", stdin);
  freopen(TASK ".out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
  return 0;
}


