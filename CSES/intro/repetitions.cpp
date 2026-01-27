#include "bits/stdc++.h"

// Repetitions

using namespace std;

typedef long long ll;

// TC: O(n) - scanning the string once
// MC: O(1)
void solve(string n) {
  char last_seen = n[0];
  int max_len = 1;
  int cur_len = 1;
  for (size_t i=1; i < n.size(); i++) {
    char cur = n[i];

    // if (cur != last_seen) {
    //   cur_len = 1;
    // } else {
    //   cur_len++;
    // }

    cur_len = (cur != last_seen) ? 1 : cur_len + 1;
    max_len = max(cur_len, max_len);
    last_seen = n[i];
  }

  cout << max_len << endl;
}

int main() {
  string inp;
  cin >> inp;
  solve(inp);
}
