#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void solve() {
  ll n; cin >> n;
  ll num_heros = 0;

  multiset<ll> heros;

  ll total_power = 0;

  for (ll i=0; i < n; i++ ) {
    ll card; cin >> card;
    if (card) {
      heros.insert(card);
    } else {
      if (heros.empty()) continue;
      auto it = heros.end();
      it--;
      total_power += *it;
      heros.erase(it);
    }
  }

  cout << total_power << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
