#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  map<int, int> f;
  for (int i=0; i < n; i++) {
    int x; cin >> x; f[x]++;
  }

  for (auto [_, x]: f) {
    if (x & 1) {
      cout << "Conan\n";
      return;
    }
  }
  cout << "Agasa\n";
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

