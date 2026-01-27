#include "bits/stdc++.h"

/// Weird Algorithm

using namespace std;

typedef long long ll;

void solve(ll n) {
  cout << n << " ";
  while (n != 1) {
    if (n & 1) {
      // odd
      n = n * 3 + 1;
    } else {
      n = n / 2;
    }
    cout << n << " ";
  }
  cout << endl;
}

int main() {
  ll n;
  cin >> n;
  solve(n);
}
