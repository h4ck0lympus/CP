#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

typedef struct {
  int l, r;
} range;

// difference array woulnd't work (a, b) <= 1e9
void solve() {
  int n; cin >> n;
  vector<int> arrivals;
  vector<int> departures;

  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    arrivals.push_back(a);
    departures.push_back(b);
  }

  sort(arrivals.begin(), arrivals.end());
  sort(departures.begin(), departures.end());

  int i=0, j=0;

  int curr = 0;
  int ans = 0;
  while (i < n && j < n) {
    if (arrivals[i] < departures[j]) {
      curr++;
      i++;
    } else {
      curr--;
      j++;
    }
    ans = max(ans, curr);
  }

  cout << ans << "\n";
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--)
    solve();
#else
  solve();
#endif
}
