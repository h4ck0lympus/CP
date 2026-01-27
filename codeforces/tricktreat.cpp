#include "bits/stdc++.h"
#include <cmath>

using namespace std;

// https://open.kattis.com/problems/tricktreat
 
// this is a katora shape function we are trying to minimize the max 
// of this function. So we will use ternary search instead of binary search
double dist_bw_points(double x1, double x2, double y1, double y2) {
  double X = (x2 - x1) * (x2 - x1);
  double Y = (y2 - y1) * (y2 - y1);
  double dist = sqrt(X + Y);
  return dist;
}

double max_time_taken(vector<double> &xs, vector<double> &ys, double D) {
  double time_taken = 0.0; // time taken by furthest child

  for (int i = 0; i < xs.size(); i++) {
    time_taken = max(time_taken, dist_bw_points(xs[i], D, ys[i], 0)); // we need furthest child so take max
  }

  return time_taken;
}

void solve(int n) {
  vector<double> xs, ys;
  double min_x = (double)INT_MAX, max_x = (double)INT_MIN;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    xs.push_back(x);
    ys.push_back(y);
    min_x = min(min_x, x);
    max_x = max(max_x, x);
  }

  double lo = min_x, hi = max_x;

  for (int i=0; i < 100; i++) {
    double delta = (hi - lo) / 3;
    double m1 = lo + delta;
    double m2 = hi - delta;
    double d1 = max_time_taken(xs, ys, m1);
    double d2 = max_time_taken(xs, ys, m2);
    if (d1 < d2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  double minimum_x = (lo + hi) / 2;
  double min_dist = max_time_taken(xs, ys, minimum_x);
  cout << fixed << setprecision(5); 
  cout << minimum_x << " " << min_dist << endl;
}

int main() {
  int n;
  while (cin >> n && n) solve(n);
}
