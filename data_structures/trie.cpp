struct trie {
  struct node {
    vector<int> children;
    int alphabetLenght = 26;
    bool end;
    node() {
      children.assign(alphabetLenght, -1);
      end = false;
    }
  };

  vector<node> root;

  trie() {
    node x;
    root.push_back(x);
  }

  void insert(string s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
      int x = s[i] - 'a';
      if (root[v].children[x] == -1) {
        root.push_back(node());
        root[v].children[x] = root.size() - 1;
      }
      v = root[v].children[x];
    }
    root[v].end = true;
  }
};
