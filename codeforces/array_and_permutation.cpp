#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

void solve() {
  int n; cin >> n;
  vector<int> p, a;

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    if (p.empty() || x != p.back()) {
      p.push_back(x);
    }
  }

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    if (a.empty() || x != a.back()) {
      a.push_back(x);
    }
  }

  int i = 0, j = 0;

  while (i < p.size() && j < a.size()) {
    if (p[i] == a[j]) {
      j++;
    } else {
      i++;
    }
  }

  cout << ((j == a.size()) ? "YES\n" : "NO\n");
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

