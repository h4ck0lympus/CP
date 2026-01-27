#include "bits/stdc++.h"

using namespace std;

#define int long long

// n bookshelves; a[i] books on it
// min time to arrange no more than k books on EACH bookshelf

// x: time taken to choose 1 bookshelf, remove all books; basically a[i] = 0
// y: time take to take all books from all n bookshelves and arrange them evenly
void solve() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;

  // if sum of books <= rearrange_threshold then we can take option 2
  // otherwise we HAVE to go with option 1
  int rearrange_threshold = n * k;

  multiset<int> bookshelves; // books in ith book shelf
  
  int sum = 0;

  // O (n * log n)
  for (int i=0; i < n; i++) {
    int books; cin >> books;
    sum += books;
    bookshelves.insert(books);
  }


  int s = sum;
  int t1 = 0;
  auto it = prev(bookshelves.end());
  while (s > rearrange_threshold) {
    // we need to use option 1 for some books    
    s -= *it;
    t1 += x;
    it--;
  }
  t1 += y; // and option 2 should handle the rest

  // OR

  // we only take option 1 and no need for option 2
  int t2 = 0;

  it = bookshelves.upper_bound(k); // first element strictly more than k
  while (it != bookshelves.end()) {
    sum -= *it;
    t2 += x;
    it++;
  }
  
  int time = min(t1, t2);
  cout << time << endl;
}

#ifdef int
#undef int
#endif
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
