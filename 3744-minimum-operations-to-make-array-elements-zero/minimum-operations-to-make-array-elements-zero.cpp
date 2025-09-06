class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries)
            ans += (getOperations(q[1]) - getOperations(q[0] - 1) + 1) / 2;
        return ans;
    }
private:
    long long getOperations(int n) {
        if (n <= 0) return 0;
        long long res = 0;
        int ops = 0;
        for (long long p = 1; p <= n; p *= 4) {
            long long l = p, r = min((long long)n, p * 4 - 1);
            res += (r - l + 1) * 1LL * ++ops;
        }
        return res;
    }
};
