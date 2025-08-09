class Solution {
 public:
  bool isSubsequence(string s, string t) {
    vector<vector<int>> pos(256);
    for (int i = 0; i < t.size(); ++i)
      pos[t[i]].push_back(i);

    int prevIndex = -1;
    for (char c : s) {
      auto &list = pos[c];
      if (list.empty()) return false;
      auto it = upper_bound(list.begin(), list.end(), prevIndex);
      if (it == list.end()) return false;
      prevIndex = *it;
    }
    return true;
  }
};
