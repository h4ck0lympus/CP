#include "bits/stdc++.h"

typedef long long ll;

using namespace std;

template <typename T>
T gcd (T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  vector<ll> arr;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    arr.push_back(x);
  }

}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
