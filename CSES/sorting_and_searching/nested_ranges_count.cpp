#include "bits/stdc++.h"

using namespace std;

#define int long long

typedef struct {
  int l, r;
  int idx;
} range;

void solve() {
  int n; cin >> n;
  vector<range> ranges;
  vector<int> contains(n), contained(n);

  for (int i=0; i < n; i++ ) {
    int x, y; cin >> x >> y;
    range r = {.l = x, .r = y, .idx = i};
    ranges.push_back(r);
  }

  sort(ranges.begin(), ranges.end(), [](range r1, range r2){
      if (r1.l == r2.l) return r1.r >= r2.r;
      return r1.l <= r2.l;
  });

  range best_range = ranges[0];
  for (int i=1; i < n; i++) {
    int best_right = best_range.r;
    range cr = ranges[i];
    if (cr.r <= best_right) {
      // cr is part of the best range
      contains[best_range.idx] += 1;
    } else {
      best_range = cr;
    }
  }

  // contained logic

  // 1 6
  // 2 4 => (1, 6)
  // 3 6 => (1, 6)
  // 4 8

  best_range = ranges[n-1];
  for (int i=n-2; i >= 0; i--) {
    int best_right = best_range.r;
    range cr = ranges[i];
    if (cr.r >= best_right) {
      contained[best_range.idx] += 1;
    } else {
      best_range = cr;
    }
  }

  for (int i=0; i < n; i++) {
    cout << contains[i] << " ";
  }
  cout << "\n";

  for (int i=0; i < n; i++) {
    cout << contained[i] << " ";
  }
  cout << "\n";
}

#ifdef int
#undef int
#endif
int main() { solve(); }
