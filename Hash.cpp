namespace Hash{
    int B1, B2;
    const int M1 = 1000000007;
    const int M2 = 1000000009;

    void init(){
        B1 = rng() % 65536;
        B2 = rng() % 65536;
    }
    struct RollingHash{
        vector<ii> hash;
        vector<ii> base;

        void construct(string &s){
            int n = s.size();
            int BS1 = 1;
            int BS2 = 1;
            hash.resize(n);
            base.resize(n);
            base[n - 1].first = exp(exp(B1, n - 1, M1), M1 - 2, M1);
            base[n - 1].second = exp(exp(B2, n - 1, M2), M2 - 2, M2);

            for(int i = n - 2; i >= 0; i--){
                base[i].first = base[i + 1].first * B1 % M1;
                base[i].second = base[i + 1].second * B2 % M2;
            }

            for(int i = 0; i < n; i ++){
                hash[i].first = ((s[i] - 'a' + 1) * BS1 % M1 + (i == 0 ? 0ll : hash[i - 1].first)) % M1;
                hash[i].second = ((s[i] - 'a' + 1) * BS2 % M2 + (i == 0 ? 0ll : hash[i - 1].second)) % M2;
                BS1 *= B1;
                BS1 %= M1;
                BS2 *= B2;
                BS2 %= M2;
            }
        }

        ii query(int l, int r){
            ii ans;
            if(l == 0) return hash[r];
            else{
                ans.first = (hash[r].first - hash[l - 1].first) * base[l].first % M1;
                ans.second = (hash[r].second - hash[l - 1].second) * base[l].second % M2;
                if(ans.first < 0) ans.first += M1;
                if(ans.second < 0) ans.second += M2;
                return ans;
            }
        }
    };
};