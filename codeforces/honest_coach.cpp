#include "bits/stdc++.h"

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  sort(arr.begin(), arr.end());

  int ans = INT_MAX;
  for (int i = 0; i < arr.size() - 1; i++) {
    ans = min(ans, arr[i + 1] - arr[i]);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
