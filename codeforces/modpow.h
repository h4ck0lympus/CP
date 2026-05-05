int modpow(int a, int e) {
  int p = 1;
  while (e) {
    if (e & 1) p = p * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }
  return p;
}


