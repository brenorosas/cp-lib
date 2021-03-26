// Obs: Colocar um " " espaço a mais no final da string para implementar os algoritmos;
//Retorna a Array de sufixos da string in
//Array contendo todos sufixos de forma ordenada.
vector<int> suffix_Array(const string& in) {
  int n = in.size(), c = 0;
  vector<int> temp(n), posBucket(n), bucket(n), bpos(n), out(n);
  for (int i = 0; i < n; i++) out[i] = i; 
  sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
  for (int i = 0; i < n; i++) {
    bucket[i] = c;
    if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
  }
  for (int h = 1; h < n && c < n; h <<= 1) {
    for (int i = 0; i < n; i++) posBucket[out[i]] = bucket[i];
    for (int i = n - 1; i >= 0; i--) bpos[bucket[i]] = i;
    for (int i = 0; i < n; i++) {
      if (out[i] >= n - h) temp[bpos[bucket[i]]++] = out[i];
    }
    for (int i = 0; i < n; i++) {
      if (out[i] >= h) temp[bpos[posBucket[out[i] - h]]++] = out[i] - h;
    }
    c = 0;
    for (int i = 0; i + 1 < n; i++) {
        int a = (bucket[i] != bucket[i + 1]) || (temp[i] >= n - h)
            || (posBucket[temp[i + 1] + h] != posBucket[temp[i] + h]);
        bucket[i] = c;
        c += a;
    }
    bucket[n - 1] = c++;
    temp.swap(out);
  }
  return out;
}

//LCP: Array que contém as interseções entre sufixos (i,i+1);
vector<int> suffix_Lcp(string &s, vector<int>&p){
    int n = s.size();
    vector<int>lcp(n);
    vector<int>c(n);
    for(int i=0;i<n;i++){
        c[p[i]]=i;
    }
    int k  = 0;
    for(int i=0;i<n-1;i++){
        int pi = c[i];
        int j = p[pi-1];
        while(s[i+k]==s[j+k]) k++;
        lcp[pi]=k;
        k = max(k-1,0);
    }
    return lcp;
}

//Busca binária utilizando Array suffix;
//Retorna true se a string p é substring da string s;
bool substring_Search(string &p, string &s, vector<int>&vet){
    int ini=0, fim = vet.size()-1;
    int n = s.size();
    int m = p.size();
    while(ini<=fim){
        int media = (ini+fim)/2;
        string aux;
        if(vet[media]+m>=n){
            aux = s.substr(vet[media],n-vet[media]);
        }
        else{
            aux = s.substr(vet[media],m);
        }
        if(aux==p) return true;
        else if(aux<p){
            ini = media+1;
        }
        else{
            fim=media-1;
        }
    }
    return false;
}
//Se string p é substring de s, retorna a posição inicial da primeira substring p;
int minSubstring_Search(string &p, string &s, vector<int>&vet){
    int ini=0, fim = vet.size()-1;
    int n = s.size();
    int m = p.size();
    int pos;
    while(ini<=fim){
        int media = (ini+fim)/2;
        string aux;
        if(vet[media]+m>=n){
            aux = s.substr(vet[media],n-vet[media]);
        }
        else{
            aux = s.substr(vet[media],m);
        }
        if(aux>=p){
            fim=media-1;
            pos=media;
        }
        else{
            ini = media+1;
        }
    }
    return pos;
}
//Se string p é substring de s, retorna a posição inicial da ultima substring p;
int maxSubstring_Search(string &p, string &s, vector<int>&vet){
    int ini=0, fim = vet.size()-1;
    int n = s.size();
    int m = p.size();
    int pos;
    while(ini<=fim){
        int media = (ini+fim)/2;
        string aux;
        if(vet[media]+m>=n){
            aux = s.substr(vet[media],n-vet[media]);
        }
        else{
            aux = s.substr(vet[media],m);
        }
        if(aux<=p){
            ini = media+1;
            pos=media;
        }
        else{
            fim=media-1;
        }
    }
    return pos;
}

//CMP para ordenar substrings (i,j) de S;
//Necessário implementar SegTree ou Sparse table no array LCP para buscar o menor no range (x+1,y);
bool cmp(pair<int,int> a, pair<int,int> b){
    int x = c[a.first];
    int y = c[b.first];
    if(x>y) swap(x,y);
    if(x==y){
        return a<b;
    }
    int menor;
    menor = range(x+1,y);
    // cout<<a.first<<' '<<b.first<<" : "<<x+1<<' '<<y<<" menor : "<<menor<<endl;
    if(menor<min(a.second-a.first+1,b.second-b.first+1)){
        return s[a.first+menor]<s[b.first+menor];
    }
    else{
        return a.second-a.first+1<b.second-b.first+1 or (a.second-a.first+1==b.second-b.first+1 and a<b);
    }
}