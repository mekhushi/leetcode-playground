class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        for (int x : nums) {
            if (x == 0) {
                count++;
                ans += count;  
            } else {
                count = 0;
            }
        }
        return ans;
    }
};
