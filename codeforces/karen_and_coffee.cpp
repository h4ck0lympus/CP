#include "bits/stdc++.h"

using namespace std;

// #define int long long

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  // n can be at max 2e5 (adding 10 for any off by domain issues)
  vector<int> ranges(2e5 + 10);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    // following 2 operations are O(1)
    ranges[l]++;
    ranges[r + 1]--;
  }

  // take prefix sum to store how many ranges agree on a temperature
  int sum = 0;
  // O(n)
  for (int i = 0; i < ranges.size(); i++) {
    sum += ranges[i];
    ranges[i] = sum;
  }

  // take another prefix sum to store how many number are good till now so we
  // can just subtract from b-a to get answer
  // O(n)
  sum = 0;
  for (int i = 0; i < ranges.size(); i++) {
    if (ranges[i] >= k)
      sum++;
    ranges[i] = sum;
  }

  // O(q)
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << ranges[b] - ranges[a-1] << endl;
  }
}

#ifdef int
#undef int
#endif
int main() { solve(); }
