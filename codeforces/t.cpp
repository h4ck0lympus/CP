/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : t
 * @created     : Sunday Feb 06, 2022 15:44:12 IST
 */

#include <bits/stdc++.h>

#define FOR(n) for (int i=0; i < n ; i++)
#define REP(I,n,a) for(int i=I; i < n; i+=a) 

using namespace std ; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // main code : 

	int N; cin >> N;
	int x[N], y[N] ;
    for(int i=0; i<N; i++) cin >> x[i];
	for (int i=0; i<N; i++) cin >> y[i];
	int max_square = 0;
	for (int i = 0; i < N; i++) { // for each first point
		for (int j = i+1; j < N; j++) { // for each second point
			int dx = x[i]-x[j], dy = y[i]-y[j];
			int square = dx*dx+dy*dy;
			// if the square of the distance between the two points is greater than
			// our current maximum, then update the maximum
			max_square = max(max_square,square);
		}
	}
	cout << max_square;
    return 0 ; 
}


