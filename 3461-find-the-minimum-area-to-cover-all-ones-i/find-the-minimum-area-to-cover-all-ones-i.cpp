class Solution {
 public:
  int minimumArea(vector<vector<int>>& grid) {
    int x1 = grid.size(), y1 = grid[0].size(), x2 = -1, y2 = -1;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j]) {
          x1 = min(x1, i);
          y1 = min(y1, j);
          x2 = max(x2, i);
          y2 = max(y2, j);
        }
    return (x2 < 0) ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
  }
};
