#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n,c,k; cin >> n >> c >> k;
  vector<int> arr(n);

  for (int i=0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  
  for (int i=0; i < n; i++) {
    int used = max((int) 0, min(k, c-arr[i]));
    k -= used;
    arr[i] += used;
    if (arr[i] <= c) c += arr[i];
  }

  cout << c << "\n";
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

