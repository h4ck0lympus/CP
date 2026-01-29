#include "bits/stdc++.h"

using namespace std;

#define int long long

// basically: given a range [a, b]
// check how many elements in this ranges are part of ranges

typedef struct {
  int l, r;
} range;

void solve() {
  // int num_recipes, min_recipes, num_questions;
  int n, k, q;
  cin >> n >> k >> q;

  vector<range> ranges;
  int minL = LONG_LONG_MAX, maxR = LONG_LONG_MIN;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    range r = {.l = x, .r = y};
    ranges.push_back(r);

    minL = min(minL, x);
    maxR = max(maxR, y);
  }

  // we can further optimize this by sorting the ranges and only checking part
  // of those ranges
  sort(ranges.begin(), ranges.end(), [](range r1, range r2) {
    if (r1.r == r2.r)
      return r1.l < r2.l;
    return r1.r < r2.r;
  });

  // TC: O(q) + O(n)
  // what if rather than calling count_containing_ranges q*(b-a) times we precompute the answer for a number
  // and then just check so rather than doing repeated work, we precompute and just answer the questions

  // precompute for each number in range

  vector<int> pre(maxR - minL + 1); // num - minR  to access answer for num ...

  for (int i=0; i < pre.size(); i++) {
    int temp = minL + i;

    int count = 0;
    for (range r : ranges) {
      if (temp >= r.l) {
        if (temp <= r.r){
          count++;
        }
      } else
        break;
    }

    pre[temp - minL] = count;
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int temp = a; temp <= b; temp++) {
      int count = pre[temp - minL];
      if (count >= k)
        res++;
    }
    cout << res << endl;
  }
}

#undef int
int main() { solve(); }
