/*
ID: vjuneja1
TASK: 
LANG: C++                 
*/
#include "bits/stdc++.h"
// #include "dbg.h"
using namespace std;

#define TASK ""
#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void hanoi(int disk, int from, int through, int to) {
  if (disk == 0) return;
  hanoi(disk - 1, from, to, through);
  cout << disk << " " << from << " " << to << "\n";
  hanoi(disk-1, through, from, to);
}

void solve() {
  int n; cin >> n;
  vector<int> arr(n);
  bool ok = true;
  bool seq = true;
  for (int i=0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] != 0) {
      ok = false;
    }
    if (arr[i] != i) {
      seq = false;
    }
  }

  if (ok) {
    cout << "YES\n";
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
  } else if (seq) {
    cout << "YES\n";
    cout << n << "\n";
    for (int i=n; i >= 1; i--) {
      cout << i << " 1 3 \n";
    }
  } else {
    cout << "NO\n";
  }
}

#undef int
int main() {
  // freopen(TASK ".in", "r", stdin);
  // freopen(TASK ".out", "w", stdout);
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

