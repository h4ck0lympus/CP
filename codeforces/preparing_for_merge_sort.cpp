#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

const int INF = (int) 1e18;
const int MOD = (int) (1e9 + 7);

void solve() {
  int n; cin >> n;
  vector<int> arr(n);

  for (int i=0; i < n; i++)  cin >> arr[i];

  // last added number in sequence (technically size of multiset = number of sequences)
  multiset<int> last;

  // map will keep track of previous number and current number
  // sequence starter number are basically the numbers with no value in array 
  // since they don't have a prev element
  map<int, int> mp; // map[prev] = curr
  
  vector<int> starters; // sequence starters
  for (int i=0; i < n; i++) {
    int curr = arr[i];
    auto seq_last = last.upper_bound(arr[i]);
    if (seq_last != last.begin()) {
      --seq_last;
      int prev = *seq_last;
      mp[prev] = curr;
      last.erase(seq_last);
      last.insert(curr);
    } else {
      last.insert(curr);
      starters.push_back(curr);
    }
  }

  for (int start: starters) {
    int s = start;
    while (s) {
      cout << s << " ";
      s = mp[s];
    }
    cout << "\n";
  }
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

