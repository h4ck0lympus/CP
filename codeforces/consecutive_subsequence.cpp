#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n; cin >> n;
  vector<int> arr(n);

  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  // vector<int> dp(n, 0); // dp[i] = num of elements in subseq if i is the last idx of the subseq

  map<int, int> dp; // dp[i] = length of longest conseq subseq ending with val i
  map<int, int> last_idx;  // index that last set dp[i]
  vector<int> parent(n, -1);

  dp[arr[0]] = 1;
  last_idx[arr[0]] = 0;

  int mx = 1, mx_idx = 0;

  for (int i=1; i < n; i++) {
    int curr = arr[i];
    int prev = arr[i] - 1;
    if (dp[prev] >= 1) {
      dp[curr] = dp[prev] + 1;
      parent[i] = last_idx[prev];
    } else {
      dp[curr] = 1;
    }
    last_idx[curr] = i;

    if (dp[curr] > mx) {
      mx = dp[curr];
      mx_idx = i;
    }
  }

  cout << mx << "\n";

  vector<int> idx;
  while (mx_idx != -1) {
    idx.push_back(mx_idx);
    mx_idx = parent[mx_idx];
  }
  reverse(idx.begin(), idx.end());

  for (int i: idx) {
    cout << i + 1 << " "; // 1 based idxing
  }

  cout << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}

