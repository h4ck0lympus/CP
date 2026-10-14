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

void solve() {
  int n, x, s;
  cin >> n >> x >> s;

  string a;
  cin >> a;

  vector<int> seats(x, 0);

  int empty = 0;   // first empty table index
  int filled = 0;  // first non-empty non-full table index
  int people = 0;

  for (char c : a) {
    while (empty < x && seats[empty] != 0) empty++;
    while (filled < x && (seats[filled] == 0 || seats[filled] == s)) filled++;
    if (c == 'I') {
      if (empty == x) continue; // no empty left, introvert has to go
      seats[empty]++;
      people++;
    }
    else if (c == 'E') {
      if (filled == x) continue; // no filled table, extrovert has to go
      seats[filled]++;
      people++;
    }
    else { // A can sit anywhere
      if (filled < x) {
        seats[filled]++;
        people++;
      } 
      else if (empty < x) {
        seats[empty]++;
        people++;
      }
    }
  }
  cout << people << '\n';
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

