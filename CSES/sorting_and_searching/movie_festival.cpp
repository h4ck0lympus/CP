#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

typedef struct {
  int start, end;
} mtime;

void solve() {
  int n; cin >> n;
  vector<mtime> movie_time;

  for (int i=0; i < n; i++) {
    int a, b; cin >> a >> b;
    mtime t = {.start = a, .end = b};
    movie_time.push_back(t);
  }

  // prioritize end time rather than start 
  // we leave theater as soon as possible
  // start later end earlier so we can still catch as many movies as possible (since duration is small)
  sort(movie_time.begin(), movie_time.end(), [](mtime m1, mtime m2){
      if (m1.end == m2.end) return m1.start < m2.start;
      return m1.end <  m2.end;
  });

  int prev_ending = movie_time[0].end;
  int curr = 1;
  for (int i=1; i < n; i++) {
    mtime m = movie_time[i];
    if (m.start >= prev_ending) {
      curr++;
      prev_ending = m.end;
    }
  }
  cout << curr << "\n";
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

