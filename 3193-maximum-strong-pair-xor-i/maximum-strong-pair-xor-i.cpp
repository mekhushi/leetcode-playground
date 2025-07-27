struct TrieNode {
    TrieNode* next[2] = {};
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            TrieNode* root = new TrieNode();

            
            for (int j = 0; j < n; ++j)
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    insert(root, nums[j]);

   
            res = max(res, getMaxXor(root, nums[i]));
        }

        return res;
    }

private:
    void insert(TrieNode* root, int num) {
        for (int i = 15; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!root->next[bit])
                root->next[bit] = new TrieNode();
            root = root->next[bit];
        }
    }

    int getMaxXor(TrieNode* root, int num) {
        int xorVal = 0;
        for (int i = 15; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (root->next[!bit]) {
                xorVal |= (1 << i);
                root = root->next[!bit];
            } else {
                root = root->next[bit];
            }
        }
        return xorVal;
    }
};
