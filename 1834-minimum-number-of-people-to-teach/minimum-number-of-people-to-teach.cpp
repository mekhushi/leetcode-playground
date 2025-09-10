class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSets(m);
        for (int i = 0; i < m; ++i)
            langSets[i] = {languages[i].begin(), languages[i].end()};

        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool canTalk = false;
            for (int lang : langSets[u])
                if (langSets[v].count(lang)) { canTalk = true; break; }
            if (!canTalk) { needTeach.insert(u); needTeach.insert(v); }
        }

        unordered_map<int, int> langCount;
        for (int u : needTeach)
            for (int lang : langSets[u])
                ++langCount[lang];

        int maxFreq = 0;
        for (auto& [_, freq] : langCount) maxFreq = max(maxFreq, freq);

        return needTeach.size() - maxFreq;
    }
};
