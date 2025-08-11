class Solution {
public:
    static constexpr int kMod = 1'000'000'007;
    static constexpr int kMaxBit = 30;

    long long modPow(long long base, long long exp) {
        long long result = 1, cur = base % kMod;
        while (exp > 0) {
            if (exp & 1) result = (result * cur) % kMod;
            cur = (cur * cur) % kMod;
            exp >>= 1;
        }
        return result;
    }

    long long modInverse(long long a) {
        return modPow(a, kMod - 2);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pows;
        for (int i = 0; i < kMaxBit; ++i)
            if ((n >> i) & 1) pows.push_back(1 << i);

        int m = pows.size();
        vector<long long> prefixProd(m);
        prefixProd[0] = pows[0] % kMod;
        for (int i = 1; i < m; ++i)
            prefixProd[i] = (prefixProd[i-1] * pows[i]) % kMod;

        vector<int> ans;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            long long prod = prefixProd[right];
            if (left > 0) prod = (prod * modInverse(prefixProd[left - 1])) % kMod;
            ans.push_back((int)prod);
        }
        return ans;
    }
};
