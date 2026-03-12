// This program was written
// by Mircea Rebengiuc
// for problem Dice Combinations
// on 08.12.2022
 
// overkill method
 
#include <stdio.h>
#include <ctype.h>
 
#define magic_sauce inline __attribute__((always_inline))
using uint = unsigned int;
using ll = long long;
 
const int MOD = 1e9+7;
 
struct Matrix {
  uint m[6][6];
};
 
magic_sauce Matrix operator * ( const Matrix &a, const Matrix &b ){
  int i, j, k;
  Matrix ret;
 
  for( i = 0 ; i < 6 ; i++ )
    for( j = 0 ; j < 6 ; j++ ){
      ret.m[i][j] = 0;
 
      for( k = 0 ; k < 6 ; k++ ){
        ret.m[i][j] += ((ll)a.m[i][k]) * b.m[k][j] % MOD;
        if( ret.m[i][j] >= MOD )
          ret.m[i][j] -= MOD;
      }
    }
 
  return ret;
}
 
const Matrix rec = {{
  { 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0 }
}};
 
const Matrix id = {{
    { 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1 },
}};
 
int main(){
  int n;
  Matrix base, ans;
  
  scanf( "%d", &n );
  n--;
 
  // we will exponatiate rec (recurence matrix) to the nth power to get the result
  base = rec;
  ans = id;
  while( n ){
    if( n & 1 )
      ans = ans * base;
 
    base = base * base;
    n >>= 1;
  }
 
  printf( "%d\n", (ans.m[0][0] + ans.m[0][1]) % MOD );
  
  return 0;
