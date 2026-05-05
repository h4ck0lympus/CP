#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

bool pref(string a, string s) {
  return s.substr(0, a.size()) == a;
}

bool suff(string a, string s) {
  return s.substr(s.size() - a.size()) == a;
}

string f(vector<string>& arr, string s) {
  int n = s.size();
  string ans(2*n-2, 0);
  vector<int> p(n), q(n);
  for (int i=0; i < 2*n-2; i++) {
    int len = arr[i].size();
    // if pref/suff and we have not already decided on a pref/suff of that length
    if (pref(arr[i], s) && !p[len]) {
      ans[i] = 'P';
      p[len] = 1;
    } else if (suff(arr[i], s) && !q[len]) {
      ans[i] = 'S';
      q[len] = 1;
    } else {
      return "";
    }
  }

  return ans;
}

void solve() {
  int n; cin >> n;
  vector<string> arr(2*n - 2);
  vector<string> mxs;
  for (int i=0; i < 2*n - 2; i++) {
    cin >> arr[i];
    if (arr[i].size() == n-1) {
      mxs.push_back(arr[i]);
    }
  }

  string a = mxs[0], b = mxs[1];
  string p1 = a + b.back(), p2 = b + a.back();
  string ans = f(arr, p1);
  if (ans.empty()) ans = f(arr, p2);
  cout << ans << "\n";
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

  // if (f(p1, strs, ans, true)) {
  //   cout << ans << "\n";
  //   return;
  // }
  //
  // if (f(p2, strs, ans, false)) {
  //   cout << ans << "\n";
  //   return;
  // }
  //
  // if (f(p2, strs, ans, true)) {
  //   cout << ans << "\n";
  //   return;
  // }
  //
  // if (f(p2, strs, ans, false)) {
  //   cout << ans << "\n";
  //   return;
  // }
  //
