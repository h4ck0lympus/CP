#include "bits/stdc++.h"

using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  // keep frequency
  map<int, int> f;
  int distinct = 0;
  int l = 0, r = 0;

  // while (r < n) {
  //   f[arr[r]]++;
  //   if (f[arr[r]] == 1) distinct += (r - l + 1);
  //   else {
  //     while (f[arr[r]] > 1) {
  //       f[arr[l]]--;
  //       l++;
  //     }
  //     distinct+= (r-l+1);
  //   }
  //   r++;
  // }
  
  while (r < n) {
    f[arr[r]]++;

    while (f[arr[r]] > 1) {
      f[arr[l]]--;
      l++;
    }

    distinct+= (r - l + 1);
    r++;
  }

  cout << distinct << endl;
}

#ifdef int
#undef int
#endif
int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve(); 
}


  // while (r < n) {
  //   if (f[arr[r]] == 0) {
  //     f[arr[r]]++;
  //   } else {
  //     while (l <= r) {
  //       f[arr[l]]--;
  //       if (f[arr[l]] == 1) {
  //         l++;
  //         break;
  //       }
  //       l++;
  //     }
  //   }
  //   distinct += (r - l + 1);
  //   r++;
  // }
  // cout << distinct << endl;
