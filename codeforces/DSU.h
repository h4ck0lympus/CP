struct DSU {
  vector<int> x;
  DSU(int n) {x.resize(n, -1);}
  bool same(int u, int v) { return find(u) == find(v); }
  int find(int u) {
    if (x[u] < 0) return u;
    x[u] = find(x[u]);
    return x[u];
  }
  int size(int u) {
    return -x[find(u)];
  }
  bool join(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return false;
    if (size(p1) > size(p2)) swap(p1, p2);
    x[p2] += x[p1];
    x[p1] = p2; // connect smaller to bigger
    return true;
  }
}
