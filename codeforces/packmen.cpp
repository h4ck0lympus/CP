#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

bool can(vector<int> pacman, vector<int> target, int T) {
  // can packman eat all targets in T time ?
  // we will check with 2 strategy:

  // check for all pacman, how many targets can they eat within T time

  int j = 0; // idx of leftmost uneaten food
  for (int i = 0; i < (int)pacman.size() && j < (int)target.size(); i++) {
    int pacman_pos = pacman[i];
    int food_pos = target[j];

    int R; // right most reachable position possible

    if (food_pos > pacman_pos) {
      // leftmost food is to the right of pacman
      // we don't go to left at all
      R = pacman_pos + T; // it can only go to right by T hops
    } else {
      int d = pacman_pos - food_pos; // how much we have pacman has to move to
                                     // reach leftmost food
      if (d > T)
        continue;
      // case-1: we first consume leftmost star then move to right if we can
      int case1 = pacman_pos + (T - 2 * d); // total time consumed to do that

      /*
       * we first hop R right to reach the nearest star R position from
       * pacman_pos while still going to left and eating left most star 
       * 2(R-p) + d <= t
       * 2(R - p) + p - x <= T 
       * 2R - 2p + p - x <= T
       * 2R - p - x <= T 
       * R <= (T + p + x) / 2
       */
      int case2 = (T + pacman_pos + food_pos) / 2;
      // we need to cover as much right distance possible while also covering
      // left most star but why ?
      R = max(case1, case2);
    }

    while (j < (int)target.size() && target[j] <= R)
      j++;
  }

  return j == (int)target.size(); // if packmen have eaten all food in given time T
}

void solve() {
  int n;
  cin >> n;
  vector<int> pacman;
  vector<int> target;

  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (x == '*')
      target.push_back(i);
    else if (x == 'P')
      pacman.push_back(i);
  }

  int result = -1;
  if (target.empty()) {
    cout << 0 << endl;
    return;
  }

  int low = 0, high = 2 * n;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (can(pacman, target, mid)) {
      result = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << result << endl;
}

int main() { solve(); }
