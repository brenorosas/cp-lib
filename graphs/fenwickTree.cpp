struct fenwickTree{
    vector<int> tree;

    fenwickTree(int n){
        tree.resize(n + 1);
    }

    void add(int p, int x){
        while(p < tree.size()){
            tree[p] += x;
            p += p& - p;
        }
    }

    int sum(int p){
        int ret = 0;
        while(p > 0){
            ret += tree[p];
            p -= p&-p;
        }
        return ret;
    }

    int sum(int l, int r){ return sum(r) - sum(l-1); }
};