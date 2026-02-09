#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 1

const int INF = (int) 1e18;

// we basically fixate on one target bank account . We won't move money from that account.
// Now how to find this bank account
// suppose there can be total S total transactions
// then let's say we choose any bank account A, the money after all banks tranfer their money to bank account A is
// = money in account A + (S - (ai / x)) * y) 

void solve() {
  int n, x, y; cin >> n >> x >> y;
  vector<int> arr(n);

  int num_txns = 0;
  for (int i=0; i < n; i++) {
    int acc; cin >> arr[i];
    num_txns += (arr[i] / x);
  }

  int ans = INT_MIN; // max possible money left in account after txns
  for (int i=0; i < n; i++) {
    int money_in_acc = arr[i];
    int money_after_txns = money_in_acc + ((num_txns - (arr[i] / x)) * y);
    ans = max(ans, money_after_txns);
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


  // int n, x, y; cin >> n >> x >> y;
  // multiset<int> arr;
  //
  // int ans = 0;
  // for (int i=0; i < n; i++) {
  //   int acc; cin >> acc; ans += acc;
  //   arr.insert(acc);
  // }
  //
  // while (arr.size() > 1) {
  //   auto mx = prev(arr.end());
  //   int num_txns = (*mx / x);
  //   ans -= (num_txns * (x-y)) + ((*mx % y) ? (x-y)/2: 0);
  //   arr.erase(mx);
  // }
  // cout << ans << "\n";
  //
  //

  // int n, x, y; cin >> n >> x >> y;
  // multiset<int> arr;
  //
  // int ans = 0;
  // int mx = INT_MIN;
  // for (int i=0; i < n; i++) {
  //   int acc; cin >> acc;
  //   arr.insert(acc);
  // }
  //
  // while (arr.size() > 1) {
  //   auto mx = prev(arr.end());
  //   auto mn = arr.begin();
  //   int money_received = *mn + (*mx / x) * y;
  //   arr.erase(mx); arr.erase(mn);
  //   arr.insert(money_received);
  // }
  //
  // cout << *(arr.begin()) << "\n";
