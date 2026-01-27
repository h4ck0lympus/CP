#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll amount_of_water(vector<int> &arr, int H) {
  ll amt = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < H) {
      amt += (H - arr[i]);
    }
  }

  return amt;
}

void solve() {
  int num_corals, total_water; // number of corals and max amount of water
  cin >> num_corals >> total_water;

  vector<int> arr;
  int ma = INT_MIN;
  for (int i = 0; i < num_corals; i++) {
    int corals;
    cin >> corals;
    arr.push_back(corals);
    ma = max(ma, corals);
  }

  ll lo = 0, hi = total_water + ma;

  ll res = 0;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (amount_of_water(arr, mid) <= total_water) {
      res = mid;
      lo = mid + 1; // we basically look higher
    } else {
      hi = mid - 1;
    }
  }

  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
