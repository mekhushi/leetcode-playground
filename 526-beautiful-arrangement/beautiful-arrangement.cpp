class Solution {
 public:
  int countArrangement(int n) {
    memo = vector<int>(1 << n, -1); 
    return dfs(n, 1, 0);
  }

 private:
  vector<int> memo;

  int dfs(int n, int pos, int mask) {
    if (pos > n) return 1;
    if (memo[mask] != -1) return memo[mask];

    int res = 0;
    for (int i = 1; i <= n; ++i)
      if (!(mask & (1 << (i - 1))) && (pos % i == 0 || i % pos == 0))
        res += dfs(n, pos + 1, mask | (1 << (i - 1)));

    return memo[mask] = res;
  }
};
