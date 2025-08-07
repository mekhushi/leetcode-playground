class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& g) {
    int n = g.size(), res = 0;
    for (int i = 0; i < n; ++i) res += g[i][i];  // Top-left diagonal
    res += dpTopRight(g) + dpBottomLeft(g);
    return res - 2 * g[n - 1][n - 1];
  }

 private:
  int dpTopRight(const vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][n - 1] = g[0][n - 1];
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (x >= y && !(x == n - 1 && y == n - 1)) continue;
        for (auto [dx, dy] : vector<pair<int, int>>{{1, -1}, {1, 0}, {1, 1}}) {
          int i = x - dx, j = y - dy;
          if (i < 0 || i >= n || j < 0 || j >= n) continue;
          if (i < j && j < n - 1 - i) continue;
          dp[x][y] = max(dp[x][y], dp[i][j] + g[x][y]);
        }
      }
    }
    return dp[n - 1][n - 1];
  }

  int dpBottomLeft(const vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[n - 1][0] = g[n - 1][0];
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (x <= y && !(x == n - 1 && y == n - 1)) continue;
        for (auto [dx, dy] : vector<pair<int, int>>{{-1, 1}, {0, 1}, {1, 1}}) {
          int i = x - dx, j = y - dy;
          if (i < 0 || i >= n || j < 0 || j >= n) continue;
          if (j < i && i < n - 1 - j) continue;
          dp[x][y] = max(dp[x][y], dp[i][j] + g[x][y]);
        }
      }
    }
    return dp[n - 1][n - 1];
  }
};
