#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

// void solve() {
//   int n; cin >> n;
//   vector<int> p(n);
//   for (int i=0; i < n; i++) cin >> p[i];
//
// }
//
void flip(vector<int>& a, int k) {
    reverse(a.begin(), a.begin() + k);
    for (int i = 0; i < k; i++) a[i] *= -1;
}

vector<int> get_pizza_flips(int n, vector<int> pizzas) {
    vector<int> ans;

    for (int i = n; i >= 1; i--) {
        int pos = -1;
        for (int j = 0; j < i; j++) {
            if (abs(pizzas[j]) == i) {
                pos = j;
                break;
            }
        }

        if (pos == i - 1 && pizzas[pos] == i) continue;
        if (pos != 0) {
            flip(pizzas, pos + 1);
            ans.push_back(pos + 1);
        }
        if (pizzas[0] > 0) {
            flip(pizzas, 1);
            ans.push_back(1);
        }
        flip(pizzas, i);
        ans.push_back(i);
    }
    return ans;
}

#undef int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
}
