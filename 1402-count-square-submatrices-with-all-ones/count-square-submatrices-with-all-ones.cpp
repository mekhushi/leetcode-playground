class Solution {
public:
    int countSquares(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size(), ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (M[i][j] && i && j)
                    M[i][j] += min({M[i-1][j], M[i][j-1], M[i-1][j-1]});
                ans += M[i][j];  
            }
        return ans;
    }
};
