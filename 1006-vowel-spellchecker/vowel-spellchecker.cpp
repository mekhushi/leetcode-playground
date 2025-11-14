class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_map<string, string> dict;
    for (auto& w : wordlist) {
      dict.emplace(w, w);
      dict.emplace("$" + lower(w), w); 
      dict.emplace(vowelKey(w), w);
    }

    vector<string> ans; 
    for (auto& q : queries) {
      string l = "$" + lower(q), v = vowelKey(q);
      if (dict.count(q)) ans.push_back(dict[q]);
      else if (dict.count(l)) ans.push_back(dict[l]);
      else if (dict.count(v)) ans.push_back(dict[v]);
      else ans.push_back("");
    }
    return ans; 
  }

 private:
  string lower(const string& s) {
    string t; for (char c : s) t += tolower(c); return t;
  }
  string vowelKey(const string& s) {
    string t; for (char c : s) t += isVowel(c) ? '*' : tolower(c); return t;
  }
  bool isVowel(char c) { return string("aeiouAEIOU").find(c) != string::npos; }
};
