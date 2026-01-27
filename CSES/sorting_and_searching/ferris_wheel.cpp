#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void solve() {
  int children, max_weight;
  cin >> children >> max_weight;

  multiset<int> weights;
  for (int i = 0; i < children; i++) {
    int x;
    cin >> x;
    weights.insert(x);
  }

  int res = 0;
  while (weights.size() != 0) {
    int weight = *weights.begin(); // take the minimum element
    int comp = max_weight - weight;
    auto ub = weights.upper_bound(comp);
    if (ub == weights.begin()) {
      // only one person per gondola
      weights.erase(weights.begin()); // remove that particular weight only
      res++;
      continue;
    }   

    ub--;

    if (ub == weights.begin()) {
      // can't put themself twice so remove only once
      weights.erase(weights.begin());
      res++;
      continue;
    }

    weights.erase(weights.begin());
    weights.erase(ub);
    res++;
  }
  cout << res << endl;
}

int main() { solve(); }
