#include "bits/stdc++.h"
#include <vector>

using namespace std;

typedef long long ll;

typedef struct {
  int l, r;
  int idx;
} range;

void print_ranges(vector<range> &ranges) {
  int num_ranges = ranges.size();
  for (int i = 0; i < num_ranges; i++) {
    cout << "l: " << ranges[i].l << " r: " << ranges[i].r << endl;
  }
}

// TC : O(n*logn) + O(n)
void solve() {
  int num_ranges;
  cin >> num_ranges;

  vector<range> ranges;
  vector<int> contains(num_ranges); // it contains a range
  vector<int> contained(num_ranges); // it's inside a range

  for (int i = 0; i < num_ranges; i++) {
    int x, y;
    cin >> x >> y;
    range r = {.l = x, .r = y, .idx = i};
    ranges.push_back(r);
  }

  // sort the interval by left side O(n logn)
  sort(ranges.begin(), ranges.end(), [](const range r1, const range r2) {
    if (r1.l == r2.l)
      return r1.r >= r2.r;
    return r1.l < r2.l;
  });

  // after sorting we have made use that subsequent left values will be less
  // than previous values so we only need to make decsion based on right side value

  int current_max = ranges[0].r;

  // O(n)
  for (int i=1; i<num_ranges; i++) {
    range cr = ranges[i];
    int cr_idx = cr.idx;
    if (current_max >= cr.r) {
      contained[cr_idx] = 1;
    } else {
      current_max = cr.r;
    }
  }

  // we also need to check for 
  // contains correctly contained logic above is fine and bulletproof
  // but contained need's further check
  // because above will fail in following case:
  // 1 10
  // 2 9 (contains = 1 but won't be marked)
  // 3 8

  int smallest = ranges[num_ranges-1].r;

  // O(n)
  for (int i=num_ranges-2; i >= 0; i--) {
    range cr = ranges[i];
    int cr_idx = cr.idx;
    if (cr.r >= smallest) {
      contains[cr_idx] = 1;
    } else {
      smallest = cr.r;
    }
  }

  for (int i=0; i < num_ranges; i++) {
    cout << contains[i] << " ";
  }
  cout << endl;

  for (int i=0; i < num_ranges; i++) {
    cout << contained[i] << " ";
  }
  cout << endl;
}

int main() { solve(); }
