/*
ID: vjuneja1
TASK: friday
LANG: C++                 
*/
#include "bits/stdc++.h"

#define TASK "friday"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n; cin >> n;
  int ans[7] = {0}; // sat, sud, mon, tues ... fri

  int days[12] = {0}; // days per month starting from jan
  days[1] = 28; // feb
  days[3] = 30; // apr
  days[5] = 30; // jun
  days[8] = 30; // sep
  days[10]= 30; // nov

  // all other days 31
  for (int i=0; i < 12; i++) {
    if (!days[i]) days[i] = 31;
  }

  // starting from 1900 to 1900+n-1
  // tc = O(400 * 12)

  int curr_jan13 = 0; // 6; // jan_13_1900 is saturday
  for (int y=0; y < n; y++) {
    bool is_leap = 0;
    int year = y + 1900;
    // century year
    if ((year % 100) == 0) is_leap = !(year % 400); // if divisible by 400 - leap year
    else is_leap = !(year % 4); // else if divisible by 4 - leap year

    for (int m=0; m < 12; m++) {
      ans[curr_jan13]++;
      int d = days[m] + (is_leap && m == 1);
      curr_jan13 = (curr_jan13 + d) % 7;
    }
  }

  for (int i=0; i < 7; i++) {
    cout << ans[i] << ((i == 6) ? "" : " ");
  }
  cout << "\n";
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


