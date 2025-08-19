class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    int i = click[0], j = click[1];
    if (board[i][j] == 'M') return board[i][j] = 'X', board;
    dfs(board, i, j);
    return board;
  }

 private:
  static constexpr int kDirs[8][2] = {
      {-1,-1},{-1,0},{-1,1},{0,-1},
      {0,1},{1,-1},{1,0},{1,1}};

  void dfs(vector<vector<char>>& b, int i, int j) {
    if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != 'E') return;
    int m = mines(b, i, j);
    b[i][j] = m ? '0' + m : 'B';
    if (!m) for (auto& d : kDirs) dfs(b, i+d[0], j+d[1]);
  }

  int mines(vector<vector<char>>& b, int i, int j) {
    int cnt = 0;
    for (auto& d : kDirs) {
      int x = i+d[0], y = j+d[1];
      if (x>=0 && y>=0 && x<b.size() && y<b[0].size() && b[x][y]=='M') cnt++;
    }
    return cnt;
  }
};
