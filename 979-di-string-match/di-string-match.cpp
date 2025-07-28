class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.length();
        vector<int> res;

        for (char c : s)
            res.push_back(c == 'I' ? low++ : high--);

        res.push_back(low);  // low == high at this point
        return res;
    }
};
