class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';
          int mask = 1 << num;
          rows[i] |= mask;
          cols[j] |= mask;
          boxes[boxIndex(i, j)] |= mask;
        }
      }
    }
    solve(board, 0, 0);
  }

 private:
  int rows[9] = {0};
  int cols[9] = {0};
  int boxes[9] = {0};

  int boxIndex(int i, int j) {
    return (i / 3) * 3 + (j / 3);
  }

  bool solve(vector<vector<char>>& board, int i, int j) {
    if (i == 9) return true;
    if (j == 9) return solve(board, i + 1, 0);
    if (board[i][j] != '.') return solve(board, i, j + 1);

    for (int num = 0; num < 9; num++) {
      int mask = 1 << num;
      int b = boxIndex(i, j);
      if ((rows[i] & mask) || (cols[j] & mask) || (boxes[b] & mask))
        continue;

      board[i][j] = num + '1';
      rows[i] |= mask;
      cols[j] |= mask;
      boxes[b] |= mask;

      if (solve(board, i, j + 1)) return true;

      board[i][j] = '.';
      rows[i] ^= mask;
      cols[j] ^= mask;
      boxes[b] ^= mask;
    }
    return false;
  }
};
