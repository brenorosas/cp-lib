// Retorna um vetor em que a posição i diz quantos caracters
// antes de i são iguais ao do prefixo.
// A posição i=0 terá valor 0, mudar esse valor não altera a função.
vector<int> KMP_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}