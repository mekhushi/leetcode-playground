class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> h(n), sum(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) h[j] = mat[i][j] ? h[j] + 1 : 0;
            stack<int> st;
            for (int j = 0; j < n; ++j) {
                while (!st.empty() && h[st.top()] >= h[j]) st.pop();
                if (!st.empty()) sum[j] = sum[st.top()] + h[j] * (j - st.top());
                else sum[j] = h[j] * (j + 1);
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};
