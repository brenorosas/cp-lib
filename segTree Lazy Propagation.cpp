 struct segTree {
    int size;
    vector<long long> vet;
    long long NO_OPERATION = LLONG_MAX;
    const long long neutral = 0;

    long long merge(long long a, long long b) {
        return a+b;
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        vet.assign(2 * size, 0);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        vet[2 * x + 1] = merge(vet[2 * x + 1], vet[x]);
        vet[2 * x + 2] = merge(vet[2 * x + 2], vet[x]);
        vet[x] = NO_OPERATION;
    }

    long long get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return vet[x];
        }
        int m = (lx + rx) / 2;
        int res;
        if (i < m) {
            res = get(i, 2 * x + 1, lx, m);
        } else {
            res = get(i, 2 * x + 2, m, rx);
        }
        return merge(res, vet[x]);
    }

    long long get(int i) { return get(i, 0, 0, size); }

    void modify(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r or l >= rx) return;
        if (lx >= l and rx <= r) {
            vet[x] = merge(vet[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
    }
    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }
};
