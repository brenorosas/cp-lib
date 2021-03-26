vector<int> parent, tam;

void make_set(int v) {
    parent[v] = v;
    tam[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (tam[a] < tam[b])
            swap(a, b);
        parent[b] = a;
        tam[a]+=tam[b];
    }
}