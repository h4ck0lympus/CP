#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int a, b; cin >> a >> b;

  // 5 1 == NO (even tho 6 % 3 == 0)
  if (a > 2 * b || b > 2 * a) {
    cout << "NO\n";
    return;
  }

  if ((a + b) % 3 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return;
}

#ifdef int
#undef int
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}


// bool s(int a, int b) {
//
//   if (a == 0 && b == 0) {
//     return true;
//   } else if (a < 0 || b < 0) {
//     return false;
//   }
//
//   int s1 = s(a-1, b-2);
//   int s2 = s(a-2, b-1);
//
//   return (bool)(s1 || s2); // if either one is 0 we good
// }
//
//
// void solve() {
//   int a, b; cin >> a >> b;
//
//   // making sure we always start from positive a and b
//   if (a == 0 && b == 0) {
//     cout << "NO\n";
//     return;
//   }
//
//   if (s(a, b)) {
//     cout << "YES\n";
//   } else {
//     cout << "NO\n";
//   }
//   return;
// }
