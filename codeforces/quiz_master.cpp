#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

void solve() {
  int n, m; cin >> n >> m;
  
  vector<int> a;
  for (int i=0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());

  map<int, set<int>> ma;
  set<int> div;

  // store number divisible by a[i] from 1 to m
  for (int i: a) {
    set<int> s;
    for (int j=i; j < m; j+=i) {
      s.insert(j);
    }
    ma[i] = s;
  }

  int l=n-2, r = n-1;

  while (l >= 0) {
    set<int> a = set_union(m[l], m[r]);
  }

  cout << "-1\n";
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

