#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// 0 <= a % b < b
//  a % b will always be < b
//  maximum(a % b) == b - 1
void solve() {
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end()); // sort to consume low possible mex first
  int mex = 0;
    // if (arr[i] == 0 || mex == 0 || arr[i] % mex == mex) mex++;
  for (int i=0; i < n; i++) {
    if (arr[i] == mex || arr[i] + 1 >= 2 * mex) mex++;
  }
  cout << mex << "\n";
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

// bi any number >= 1 
// so this won't work

// given an arr - find mex
// https://cp-algorithms.com/sequences/mex.html
// void solve() {
//   int n; cin >> n;
//   vector<int> arr(n);
//   map<int, int> mp; // freq
//   set<int> s; // missing number
//   for (int i=0; i <= n; i++) s.insert(i);
//   for (int i=0; i < n; i++) {
//     cin >> arr[i];
//     mp[arr[i]]++;
//   }
//
//   for (int i=1; i <= n; i++) {
//     int num = arr[i-1] % i;
//     mp[num]--;
//     s.erase(num);
//   }
//
//   cout << *s.begin() << "\n";
// }
