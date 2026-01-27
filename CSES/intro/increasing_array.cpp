#include "bits/stdc++.h"

// increasing array

using namespace std;

typedef long long ll;

// tc: o(n + (n -1)) = O(n) - scanning the arr twice
// mc: o(1)
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  vector<ll> arr;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    arr.push_back(x);
  }

  ll moves = 0;
  ll p = arr[0];
  for (int i = 1; i < n; i++) {
    ll c = arr[i];
    if (p > c) {
      moves += p - c;
      c = p; // changed p+1 to p -- increasing not strictly increasing...
    }
    p = c;
  }

  cout << moves << endl;
}

int main() { solve(); }
