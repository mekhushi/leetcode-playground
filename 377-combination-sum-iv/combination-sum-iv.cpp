class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> memo(target + 1, -1);
    memo[0] = 1;
    return dfs(nums, target, memo);
  }

 private:
  int dfs(vector<int>& nums, int target, vector<int>& memo) {
    if (memo[target] != -1) return memo[target];
    long res = 0;
    for (int num : nums)
      if (target >= num)
        res += dfs(nums, target - num, memo);
    return memo[target] = (int)res;
  }
};
