#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;

  // ticket prices
  multiset<ll> ticket;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ticket.insert(x);
  }

  // max customers can pay
  for (int i = 0; i < m; i++) {
    ll x; cin >> x;
    // i want most expensive ticket <= x
    auto it = ticket.upper_bound(x); // first element greater than the given key
    if (it == ticket.begin()) { // if the ticket doesn't exist
      cout << "-1\n";
    } else {
      it--; // decrement 1 to get the <= element
      cout << *it << endl;
      ticket.erase(it);
    }
  }
}

int main() { solve(); }

/* 
 * using ticket.begin is correct because let's take the following example: 
 * tickets = {5, 7, 9}
 * x = 3
 * upper_bound(3) --> 5
 * now one less than this will return undefined behaviour

