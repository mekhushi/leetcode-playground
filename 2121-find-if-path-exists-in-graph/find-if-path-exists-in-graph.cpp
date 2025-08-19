class UnionFind {
 public:
  UnionFind(int n): id(n), r(n) { iota(id.begin(), id.end(), 0); }

  void unite(int u, int v) {
    int i = find(u), j = find(v);
    if (i == j) return;
    if (r[i] < r[j]) id[i] = j;
    else if (r[i] > r[j]) id[j] = i;
    else id[i] = j, r[j]++;
  }

  int find(int u) { return id[u] == u ? u : id[u] = find(id[u]); }

 private:
  vector<int> id, r;
};

class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
    UnionFind uf(n);
    for (auto& e : edges) uf.unite(e[0], e[1]);
    return uf.find(s) == uf.find(d);
  }
};
