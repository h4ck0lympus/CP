#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n, x; cin >> n >> x; // num books, max total price
  vector<int> prices(n+1);
  vector<int> books(n+1);

  for (int i=0; i < n; i++) {
    cin >> prices[i];
  }

  for (int i=0; i < n; i++) {
    cin >> books[i];
  }

  vector<int> dp(x+1);
  dp[0] = 0; // budget = 0, no books purchaed
  
  // for (int i=1; i <= x; i++) { // budget
  //   for (int j=0; j < n; j++) { // pages
  //     int price = prices[j]; // price of current book
  //     int pg = pages[j]; // number of pages in current book
  //     if (i - price >= 0) dp[i] = max(dp[i], (dp[i-price] + pg) % MOD);
  //   }
  // }

  // for each book, we are checking if we can buy it or not
  // if we buy it then with rest of money how many books (num of pages) can we buy 
  // otherwise what happens if we don't buy
  for (int i=0; i < n; i++) { // for each book
    int price = prices[i];
    int pages = books[i];
    for (int j=x; j>=0; j--) {
      if (j >= price) { // if we can buy this book
        dp[j] = max(dp[j], dp[j-price] + pages);
      }
    }
  }

  cout << dp[x] << "\n";

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

