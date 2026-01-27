#include "bits/stdc++.h"

using namespace std;

#define int long long
const int MOD = 1e9+7;

void solve() {
  int n; cin >> n;
  int sum = (n * (n+1))/2;

  if (sum & 1){
    cout << "NO\n";
    return;
  }
  
  int target = sum / 2;
  set<int> s1, s2;

  for (int i=n; i > 0; i--) {
    if (i <= target) {
      s1.insert(i);
      target -= i;
    } else {
      s2.insert(i);
    }
  }

  cout << "YES\n";
  cout << s1.size() << "\n";
  for (auto it=s1.begin(); it != s1.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
  cout << s2.size() << "\n"; 
  for (auto it=s2.begin(); it != s2.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
}

#ifdef int
#undef int
#endif
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
