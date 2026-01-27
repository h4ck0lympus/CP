/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : jzzhu_and_children
 * @created     : Sunday Jan 01, 2023 19:16:25 MST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)

using ll = long long;

using namespace std ; 

list<int> l{}; 

void printList() 
{
    for (auto e = l.begin(); e != l.end(); e++) 
        cout << ' ' << *e;
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    // main code : 
    int n,m; cin >> n >> m;
    for (int i=0; i < n; i++) {
        int n; cin >> n;
        l.push_front(n); 
    }
    
    // while only one element is left 
    int i = 0; 
    while (l.size() > 1) {
        int front = l.front();
        front = front - m;
        if (front <= 0) {
            l.pop_front();
        } else {
            // push to back
            l.pop_front();
            l.push_back(front); 
        }
        // cout << "after: ";
        // printList();
        i++; 
    }

    cout << i << "\n";

    return 0 ; 
}


