#include "bits/stdc++.h"

using namespace std;

string biggerIsGreater(string w) {
    int n = w.size();
    int i = n-2;
    while (i >= 0 && w[i] >= w[i+1]) {
        i--;
    }
    if (i < 0) return "no answer";
    int j = n-1;
    while (j > i && w[j] <= w[i]) {
        j--;
    }
    swap(w[i], w[j]);
    reverse(w.begin() + i + 1, w.end());
    return w;
}

