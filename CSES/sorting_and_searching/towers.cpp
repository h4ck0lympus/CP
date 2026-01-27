#include "bits/stdc++.h"

using namespace std;

void solve() {
  int n;
  cin >> n;

  int towers = 0;
  multiset<int> tower_heads;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = tower_heads.upper_bound(x);
    if (it == tower_heads.end()) { 
	// if no suitable tower found, make a new tower with element
	towers++;
	tower_heads.insert(x);
    } else {
	// tower_heads.erase(*it)
	//
	tower_heads.erase(it); // we remove the old head 
	tower_heads.insert(x); // this is the new head of the previously established tower
    }
  }

  cout << towers << endl;
}

int main() { 
    solve(); 
}

/*
given input:

{3, 8}
5
3 8 2 1 5

tower-1: 3 -> 2 -> 1
tower-2: 8 -> 5

so minimum number of towers = 2
*/
