#include "bits/stdc++.h"

using namespace std;

#define int long long

vector<int> prefix_sum;
void solve() {
  prefix_sum.push_back(0);
  int n, q; cin >> n >> q;

  int sum = 0;
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    sum+= x;
    prefix_sum.push_back(sum);
  }

  while (q--) {
    int l, r; cin >> l >> r;
    cout << prefix_sum[r] - prefix_sum[l] << endl;
  }
}

#ifdef int
#undef int
#endif
int main() {
    solve();
}
