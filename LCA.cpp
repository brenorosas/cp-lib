vector<int> adj[200200];
const int l = ceil(log2(200200)) + 1;
int h[200200];
int up[200200][l];
int timer;
int tin[200200], tout[200200];
void dfs(int v, int anc) {
    up[v][0] = anc;
    if (v != anc) h[v] = h[anc] + 1;
    // Tempo de entrada;
    tin[v] = ++timer;
    // Pega quem ta 2^i a cima;
    for (int i = 1; i < l; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int &to : adj[v]) {
        if (to != anc) {
            dfs(to, v);
        }
    }
    // Tempo de saída;
    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    }
    if (isAncestor(v, u)) {
        return v;
    }
    for (int i = l - 1; i >= 0; i--) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}
// Distância em o(log n)
int distLog(int u, int v) {
    int x = 0;
    if (u == v) return x;
    for (int i = l - 1; i >= 0; i--) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
            x += (1 << i);
        }
    }
    return x + 1;
}
// Distância em o(1) (Precisa precalcular Altura);
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u, v)]; }

// Apenas se tem altura <= K;
int kup(int u, int k) {
    for (int i = 0; i < 32; i++) {
        if ((k >> i) & 1) {
            u = up[u][i];
        }
    }
    return u;
}
