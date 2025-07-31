class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur;
        
        for (int a : arr) {
            unordered_set<int> next;
            next.insert(a);
            for (int val : cur) 
                next.insert(val | a);
            cur = move(next);
            res.insert(cur.begin(), cur.end());
        }
        
        return res.size();
    }
};
