class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    vector<double> v(nums.begin(), nums.end());
    return dfs(v);
  }

 private:
  bool dfs(vector<double>& v) {
    if (v.size() == 1) return fabs(v[0] - 24) < 1e-3;

    for (int i = 0; i < v.size(); i++)
      for (int j = 0; j < i; j++)
        for (double x : generate(v[i], v[j])) {
          vector<double> nxt;
          nxt.reserve(v.size() - 1);
          nxt.push_back(x);
          for (int k = 0; k < v.size(); k++)
            if (k != i && k != j) nxt.push_back(v[k]);
          if (dfs(nxt)) return true;
        }
    return false;
  }

  vector<double> generate(double a, double b) {
    return {a + b, a - b, b - a, a * b, a / b, b / a};
  }
};
