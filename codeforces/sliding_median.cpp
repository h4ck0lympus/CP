#include "bits/stdc++.h"
#include <set>

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n, k; cin >> n >> k;
  vector<int> arr;

  for (int i=0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }

  multiset<int> m;
 
  for (int i=0; i < k; i++) {
    m.insert(arr[i]);
  }

  // auto start = next(m.begin()); // point to min element in multiset
  auto mid = next(m.begin(), (int)(k - 1)/2); // point to mid (median)
  // auto end = prev(m.end()); // point to max element in multiset 

  cout << *mid << " ";
  int i=0, j=k;

  // add small, remove big, median left
  // add big, remove small, median right
  while (j < n) {
    int outgoing = arr[i];
    int incoming = arr[j];

    m.insert(incoming);
    // we decrement mid because we want lower mid 
    // adding less than current median will lower the median
    if (incoming < *mid) {
      mid--;
    }

    // add big, remove small, median right
    if (outgoing <= *mid) {
      mid++;
    }

    m.erase(m.find(outgoing));
    
    assert(m.size() == k);
    cout << *mid << " ";
    i++;
    j++;
  }

  cout << "\n";
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

// {2, 3, 4}
//
