/*
ID: vjuneja1
TASK: gift1
LANG: C++                 
*/
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define HAVE_TESTCASES 0

void solve() {
  int n; cin >> n;
  map<string, int> ac; // gift account
  vector<string> names;

  for (int i=0; i < n; i++) {
    string name; cin >> name;
    names.push_back(name);
    ac[name] = 0;
  }

  for (int i=0; i < n; i++) {
    string giver; cin >> giver;
    int amount, num_givee; cin >> amount >> num_givee;

    int amt_per_person = 0, amt_left = 0;
    if (num_givee != 0) {
      amt_per_person = amount / num_givee;
      amt_left = (amount % num_givee) - amount;
    } 
    ac[giver] += amt_left;
    for (int j=0; j < num_givee; j++) {
      string givee_name; cin >> givee_name; 
      ac[givee_name] += amt_per_person;
    }
  }

  for (string name: names) {
    cout << name << " " << ac[name] << "\n";
  }
}

#undef int
int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
#if HAVE_TESTCASES
  int t;
  cin >> t;
  while (t--) solve();
#else
  solve();
#endif
  return 0;
}


