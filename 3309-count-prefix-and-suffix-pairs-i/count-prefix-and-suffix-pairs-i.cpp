struct TrieNode {
    TrieNode* children[26] = {};
    vector<int> wordIndices;
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode();
        
       
        for (int i = 0; i < n; ++i) {
            insert(root, words[i], i);
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> prefixMatch = getPrefixMatch(root, words[i]);

            for (int j : prefixMatch) {
                if (i < j && isSuffix(words[j], words[i])) {
                    ++count;
                }
            }
        }

        return count;
    }

private:
    void insert(TrieNode* root, const string& word, int index) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
            node->wordIndices.push_back(index);
        }
    }

    vector<int> getPrefixMatch(TrieNode* root, const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) return {};
            node = node->children[c - 'a'];
        }
        return node->wordIndices;
    }

    bool isSuffix(const string& word, const string& suffix) {
        if (suffix.size() > word.size()) return false;
        return word.compare(word.size() - suffix.size(), suffix.size(), suffix) == 0;
    }
};
