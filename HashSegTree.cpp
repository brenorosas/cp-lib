namespace Hash{
    int B1, B2;
    const int M1 = 1000000007;
    const int M2 = 1000000009;
    void init(){
        B1 = rng() % 65536;
        B2 = rng() % 65536;
    }

    struct hash{
        int h1;
        int h2;
        int sz;

        bool operator==(const hash y) const {
            return (this->h1 == y.h1 and this->h2 == y.h2 and this->sz == y.sz);
        }
    };

    struct stHash{
        int size;
        vector<hash> vet;
        hash neutral;
        vector<ii> base;
        void init(int n){
            size = 1;
            while(size<n)
                size*=2;
            vet.resize(2*size);
            neutral.h1 = 0;
            neutral.h2 = 0;
            neutral.sz = 0;
            base.resize(n + 1);
            base[0] = {1, 1};
            for(int i = 1; i <= n; i++){
                base[i].first = (base[i - 1].first * B1) % M1;
                base[i].second = (base[i - 1].second * B2) % M2;
            }
        }

        hash merge(hash a, hash b){
            hash ans;
            ans.h1 = (a.h1 + (b.h1 * base[a.sz].first) % M1) % M1;
            ans.h2 = (a.h2 + (b.h2 * base[a.sz].second) % M2) % M2;
            ans.sz = a.sz + b.sz;
            return ans; 
        }

        void build(string &a, int x, int lx, int rx){
            if(rx-lx == 1){
                if(lx < (int)a.size()){
                    vet[x].h1 = vet[x].h2 = (a[lx] - 'a' + 1);
                    vet[x].sz = 1;
                }
                return;
            }
            int m = (lx+rx)/2;
            build(a, 2*x+1, lx, m);
            build(a, 2*x+2, m, rx);
            vet[x] = merge(vet[2*x+1],vet[2*x+2]);
        }

        void build(string &a){
            build(a,0,0,size);
        }

        void set(int i, char v, int x, int lx, int rx){
            if(rx - lx == 1){
                vet[x].h1 = vet[x].h2 = (v - 'a' + 1);
                vet[x].sz = 1;
                return;
            }
            int m = (lx+rx)/2;
            if(i<m){
                set(i,v,2*x+1,lx,m);
            } else {
                set(i,v,2*x+2,m,rx);
            }
            vet[x] = merge(vet[2*x+1],vet[2*x+2]);
        }

        void set(int i, char v){
            set(i,v,0,0,size);
        }

        hash range(int l, int r, int x, int lx, int rx){
            if(lx>=r or l>=rx) return neutral;
            if(lx>=l and rx<=r){
                return vet[x];
            }
            int m = (lx+rx)/2;
            hash s1 = neutral, s2 = neutral;
            s1 = range(l,r,2*x+1,lx,m);
            s2 = range(l,r,2*x+2,m,rx);
            return merge(s1,s2);
        }
        //Retorna o range entre l e r-1
        hash range(int l,int r){
            return range(l,r,0,0,size);
        }
    };
}