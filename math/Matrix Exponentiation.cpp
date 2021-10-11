#define Matrix vector<vector<int>>

// Retorna matriz identidade n*n
Matrix identity(const int n) {
  assert(n > 0);

  Matrix mat_identity(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++)
    mat_identity[i][i] = 1;

  return mat_identity;
}

// Retorna matriz resultande da multiplicação entre matriz a e b;
Matrix matrixMult(const Matrix &a, const Matrix &b) {
  Matrix ans(a.size(), vector<int>(b.front().size(), 0));

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans.front().size(); j++) {
      for (int k = 0; k < a.front().size(); k++) {
        ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return ans;
}

// Matriz a^b
Matrix matrixExp(Matrix a, int b) {
  Matrix ans = identity(2);
  while (b > 0) {
    if (b & 1)
      ans = matrixMult(ans, a);
    b >>= 1;
    a = matrixMult(a, a);
  }
  return ans;
}

// Transforma vetor em matriz, (tamanho do vetor precisa ser quadrado perfeito);
Matrix matrix(vector<int> &vet) {
  int n = sqrt(vet.size());
  Matrix ans(n, vector<int>(n, 0));
  for (int i = 0; i < vet.size(); i++) {
    int l = i / n;
    int c = i % n;
    ans[l][c] = vet[i];
  }
  return ans;
}