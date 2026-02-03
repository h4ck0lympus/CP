#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

typedef struct {
  int n, idx;
} num;

// using 2 pointer
void solve() {
  int n, x; cin >> n >> x;

  vector<num> arr;

  for (int i=0; i < n; i++) {
    int ai; cin >> ai;
    num an = {.n = ai, .idx = i};
    arr.push_back(an);
  }

  sort(arr.begin(), arr.end(), [](num n1, num n2){return n1.n < n2.n;});

  int i=0, j = n-1;

  while (i < j) {
    num n1 = arr[i];
    num n2 = arr[j];
    int sum = n1.n + n2.n;
    if (sum == x) {
      cout << n1.idx+1 << " " << n2.idx+1 << "\n";
      return;
    } else if (sum > x) {
      j--;
    } else {
      i++;
    }
  }

  cout << "IMPOSSIBLE\n";
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


// using hashmap
// void solve() {
//   int n, x; cin >> n >> x;
//
//   vector<int> arr;
//   map<int, int> m;
//   for (int i=0; i < n; i++) {
//     int num; cin >> num;
//     arr.push_back(num);
//     m[num] = i;
//   }
//
//   for (int i=0; i < n; i++) {
//     int comp = x - arr[i];
//     if (m.count(comp) >= 1 && m[comp] != i) {
//       cout << i+1 << " " << m[comp]+1 << "\n"; // 0 idx to 1 idx
//       return;
//     }
//   }
//
//   cout << "IMPOSSIBLE\n";
// }
//
