#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n; cin >> n;
  vector<int> pref;
  int sum = 0;
  // pref.push_back(0);

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    sum += x;
    pref.push_back(sum);
  }

  if (sum % 3) {
    cout << "0\n";
    return;
  }

  int need_sum = sum / 3;

  int s = 0;
  int ans = 0;

  // to make 3 stripes, essentially we need to cut stripe TWICE
  // we also need to make sure that there is some blocks left after second cut for 3rd piece to exist
  for (int i=0; i<n-1; i++) {

    // there might be negative numbers, so multiple ways to cut stripe 
    // we first check if we can cut for 2 * s and see if we have found any s before that
    // if found if basically add that to ans
    if (i > 0 && pref[i] == 2 * need_sum) {
      ans += s;
    } 

    if (pref[i] == need_sum) {
      s++;
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

