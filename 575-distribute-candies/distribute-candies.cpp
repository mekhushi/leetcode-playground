class Solution {
public:
    int distributeCandies(vector<int>& C) {
        unordered_set<int> cset(begin(C), end(C));
        return min(cset.size(), C.size() / 2);
    }
};