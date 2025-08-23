class Solution {
 public:
  int minimumSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = m * n;

    for (int i = 0; i < m; i++) {
      int top = area(grid, 0, i, 0, n - 1);
      for (int j = 0; j < n; j++)
        ans = min(ans, top + area(grid, i + 1, m - 1, 0, j) +
                          area(grid, i + 1, m - 1, j + 1, n - 1));
    }

    for (int i = 0; i < m; i++) {
      int bottom = area(grid, i, m - 1, 0, n - 1);
      for (int j = 0; j < n; j++)
        ans = min(ans, bottom + area(grid, 0, i - 1, 0, j) +
                            area(grid, 0, i - 1, j + 1, n - 1));
    }

    for (int j = 0; j < n; j++) {
      int left = area(grid, 0, m - 1, 0, j);
      for (int i = 0; i < m; i++)
        ans = min(ans, left + area(grid, 0, i, j + 1, n - 1) +
                          area(grid, i + 1, m - 1, j + 1, n - 1));
    }

    for (int j = 0; j < n; j++) {
      int right = area(grid, 0, m - 1, j, n - 1);
      for (int i = 0; i < m; i++)
        ans = min(ans, right + area(grid, 0, i, 0, j - 1) +
                           area(grid, i + 1, m - 1, 0, j - 1));
    }

    for (int i1 = 0; i1 < m; i1++)
      for (int i2 = i1 + 1; i2 < m; i2++)
        ans = min(ans, area(grid, 0, i1, 0, n - 1) +
                           area(grid, i1 + 1, i2, 0, n - 1) +
                           area(grid, i2 + 1, m - 1, 0, n - 1));

    for (int j1 = 0; j1 < n; j1++)
      for (int j2 = j1 + 1; j2 < n; j2++)
        ans = min(ans, area(grid, 0, m - 1, 0, j1) +
                           area(grid, 0, m - 1, j1 + 1, j2) +
                           area(grid, 0, m - 1, j2 + 1, n - 1));

    return ans;
  }

 private:
  int area(vector<vector<int>>& g, int si, int ei, int sj, int ej) {
    int x1 = INT_MAX, y1 = INT_MAX, x2 = -1, y2 = -1;
    for (int i = si; i <= ei; i++)
      for (int j = sj; j <= ej; j++)
        if (g[i][j]) {
          x1 = min(x1, i), y1 = min(y1, j);
          x2 = max(x2, i), y2 = max(y2, j);
        }
    return x1 == INT_MAX ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
  }
};
