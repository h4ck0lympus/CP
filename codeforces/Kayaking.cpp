#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n; cin >> n; // num kayaks
    vector <int> arr;

    for (int i=0; i < 2*n; i++) {
	int x; cin >> x;
	arr.push_back(x);
    }

    // 1. sort
    sort(arr.begin(), arr.end());



}

int main()
{
    solve();
}
