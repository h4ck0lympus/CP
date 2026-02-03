#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  string s; cin >> s;
  int freq[26] = {0};

  for (char c: s) {
    freq[c-'A']++;
  }

  // there can only be one odd freq char
  
  string res_pre = "";
  string res_mid = "";
  bool seen_odd = false;

  for (int i=0; i < 26; i++) {
    char c = (char)('A' + i);
    if (freq[i] & 1) {
      if (seen_odd) {
        cout << "NO SOLUTION\n";
        return;
      }
      for (int j=0; j < freq[i]; j++) res_mid += c;
      seen_odd = true;
    } else {
      for (int j=0; j < freq[i] / 2; j++) res_pre += c;
    }
  }
  string res_suf = res_pre;
  reverse(res_suf.begin(), res_suf.end());
  cout << res_pre + res_mid + res_suf << "\n";
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

