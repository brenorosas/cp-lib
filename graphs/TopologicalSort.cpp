const int maxn = 200200;
int qt[maxn];
vector<int> adj[maxn];
vector<int> ans;
int n;
void TopologicalSort() {
  // Smallest topological sort = priority_queue
  // priority_queue<int, vector<int>, greater<int>> fila;
  queue<int> fila;
  for (int i = 1; i <= n; i++) {
    if (qt[i] == 0) {
      fila.push(i);
    }
  }
  while (!fila.empty()) {
    int v = fila.front();
    fila.pop();
    ans.push_back(v);
    for (int &to : adj[v]) {
      qt[to]--;
      if (qt[to] == 0) {
        fila.push(to);
      }
    }
  }
}