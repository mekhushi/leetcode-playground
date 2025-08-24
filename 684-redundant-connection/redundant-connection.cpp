class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1), rank(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int u) {
      return parent[u] == u ? u : parent[u] = find(parent[u]);
    };

    auto unite = [&](int u, int v) {
      u = find(u), v = find(v);
      if (u == v) return false;
      if (rank[u] < rank[v]) swap(u, v);
      parent[v] = u;
      if (rank[u] == rank[v]) rank[u]++;
      return true;
    };

    for (auto& e : edges)
      if (!unite(e[0], e[1])) return e;

    return {};
  }
};
