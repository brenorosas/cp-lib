// Retorna um vetor em que a posição i diz quantos caracters
// antes de i são iguais ao do prefixo.
// A posição i=0 terá valor 0, mudar esse valor não altera a função.
struct KMP{
    vector<int> automato;
    string pattern;

    //constroi automato em q a posição i diz quantos caracters antes de i são iguais ao do prefixo
    void construct(string &s){
        pattern = s;
        int n = (int)s.length();
        automato.resize(n);
        for (int i = 1; i < n; i++) {
            int j = automato[i-1];
            while (j > 0 && s[i] != s[j])
                j = automato[j-1];
            if (s[i] == s[j])
                j++;
            automato[i] = j;
        }
    }

    // retorna qual o próximo estado e se o estado atual causa um match com o pattern inteiro
    pair<int, bool> go(int state, char c){
        pair<int, bool> ans;
        ans.second = false;
        if(c == pattern[state]){
            state++;
            if(state == automato.size())
                ans.second = true;
        }
        else{
            while(c != pattern[state] and state > 0)
                state = automato[state - 1];
            if(c == pattern[state])
                state++;
        }
        if(state == automato.size())
            state = automato[state - 1];
        ans.first = state;
        return ans;
    }

    // retorna todas as posições de s em que da um match com o pattern (as posições iniciais das substrings que dão match)
    vector<int> match(string &s){
        int n = (int)s.size();
        vector<int> ans;
        for(int i = 0, j = 0; i < n; i++){
            pair<int, bool> state = go(j, s[i]);
            j = state.first;
            if(state.second)
                ans.push_back(i - pattern.size() + 1);
        }
        return ans;
    }
};