/*
ID: vjuneja1
TASK: ride
LANG: C++                 
*/
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  string comet, group; cin >> comet >> group;

  int group_num = 1, comet_num = 1;

  for (char c: group) {
    group_num = (group_num * (c - 'A' + 1)) % 47;
  }


  for (char c: comet) {
    comet_num = (comet_num * (c - 'A' + 1)) % 47;
  }

  if (group_num == comet_num) {
    cout << "GO\n";
  } else {
    cout << "STAY\n";
  }
}

#undef int
int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);

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


