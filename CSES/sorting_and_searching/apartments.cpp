#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> applicant; // desired apartment size for ai applicant
  vector<int> apartment; // desired apartment size for ai applicant

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    applicant.push_back(x);
  }

  for (int i=0; i < m; i++) {
    int x; cin >> x;
    apartment.push_back(x);
  }

  sort(applicant.begin(), applicant.end());
  sort(apartment.begin(), apartment.end());

  int i=0, j=0;

  int ans = 0;
  while (i < m && j < n) {
    int mn = applicant[j] - k, mx = applicant[j] + k;   
    if (apartment[i] < mn) {
      // apartment too small - check next apartment
      i++;
    } else if (apartment[i] > mx) {
      // apartment too big - check for next applicant
      j++;
    } else {
      // exact size - match
      i++;
      j++;
      ans++;
    }
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
  while (t--) solve();
#else
  solve();
#endif
}

