#include "bits/stdc++.h"

// Missing Number

using namespace std;

typedef long long ll;

void solve(ll n, ll real_sum) {
  ll sum = n * (n + 1) / 2;
  cout << sum - real_sum << endl;
}

int main() {
  ll n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n - 1; i++) {
    ll x;
    cin >> x;
    sum += x;
  }
  solve(n, sum);
}
