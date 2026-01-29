#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define int long long

bool get_median(vector<int> &arr, int median, int k) {
  int n = (int)(arr.size());

  vector<int> median_arr;

  // easilly find median
  // median in child-level terms is "how many elements are greater than or equal to a value"
  for (int i = 0; i < n; i++) {
     int x = (arr[i] >= median) ? 1 : -1; // that's what we do
     median_arr.push_back(x);
  }

  int sum = 0;
  vector<int> prefix_sum;
  prefix_sum.push_back(0);
  for (int i=1; i < n; i++) {
    sum += median_arr[i-1];
    prefix_sum.push_back(sum);
  }


}

// we need to output the max median from a subarray of k elements
void solve() {
  int n, k; // total size, min subarray size
  cin >> n >> k;

  vector<int> arr;
  int mi = INT_MAX, ma = INT_MIN;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
    mi = min(mi, x);
    ma = max(ma, x);
  }

  int res = -1;
  int lo = mi, hi = ma;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (get_median(arr, mid, k)) {
      res = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << res << endl;
}

#ifdef int
#undef int
#endif
int main() { solve(); }
