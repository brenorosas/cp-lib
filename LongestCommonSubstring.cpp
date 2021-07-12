int LongestCommonSubstring(string s, string t){
    int n = s.size();
    vector<int> base(n + 1, 0);
    vector<int> newbase(n+1);
    int ans = 0;
    for(char &ct : t){
        for(int i = 1; i < n + 1; i++){
            newbase[i] = 0;
            if(s[i - 1] == ct){
                newbase[i] = base[i - 1] + 1;
                ans = max(ans, newbase[i]);
            }
        }
        base = newbase;
    }
    return ans;
}