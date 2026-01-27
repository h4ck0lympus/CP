#include "bits/stdc++.h"

using namespace std;

#define int long long

typedef struct {
  int weight, pos, direction;
} cow;

void print_cows(vector<cow>& cows) {
  int N = cows.size();
  for (int i = 0; i < N; i++) {
    cout << "cow " << i << " w: " << cows[i].weight << " pos: " << cows[i].pos
         << " dir: " << cows[i].direction << endl;
  }
}

void solve() {
  int N, L;
  cin >> N >> L;

  deque<cow> cows; // using deque so i can remove from both direction

  int total_weight = 0;
  int weight_reached = 0;

  for (int i = 0; i < N; i++) {
    int w, x, d;
    cin >> w >> x >> d;
    total_weight += w;
    cow c = {.weight = w, .pos = x, .direction = d};
    cows.push_back(c);
  }

  sort(cows.begin(), cows.end(),
       [](cow c1, cow c2) { return c1.pos < c2.pos; });


}

#ifdef int
#undef int
#endif
int main() {
  freopen("meetings.in", "r", stdin);
  freopen("meetings.out", "w", stdout);
  solve();
}
