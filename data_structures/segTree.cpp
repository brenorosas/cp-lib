struct segTree {
  int size;
  vector<long long> vet;

  const long long neutral = 0;

  void init(int n) {
    size = 1;
    while (size < n)
      size *= 2;
    vet.resize(2 * size);
  }

  long long merge(long long a, long long b) { return max(a, b); }

  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        vet[x] = a[lx];
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    vet[x] = merge(vet[2 * x + 1], vet[2 * x + 2]);
  }

  void build(vector<int> &a) { build(a, 0, 0, size); }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      vet[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    vet[x] = merge(vet[2 * x + 1], vet[2 * x + 2]);
  }

  void set(int i, int v) { set(i, v, 0, 0, size); }

  long long range(int l, int r, int x, int lx, int rx) {
    if (lx >= r or l >= rx)
      return neutral;
    if (lx >= l and rx <= r)
      return vet[x];
    int m = (lx + rx) / 2;
    long long s1 = range(l, r, 2 * x + 1, lx, m);
    long long s2 = range(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
  }
  // Retorna o range entre l e r-1
  long long range(int l, int r) { return range(l, r, 0, 0, size); }
};