class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> clean;
        clean.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                clean.push_back(nums[i]);
            }
        }

        int ans = 0;
        for (int i = 1; i + 1 < clean.size(); ++i) {
            if ((clean[i - 1] < clean[i] && clean[i] > clean[i + 1]) ||
                (clean[i - 1] > clean[i] && clean[i] < clean[i + 1])) {
                ++ans;
            }
        }

        return ans;
    }
};
