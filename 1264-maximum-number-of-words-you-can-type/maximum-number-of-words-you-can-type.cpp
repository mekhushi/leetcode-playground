class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        int brokenMask = 0;

        for (char c : brokenLetters)
            brokenMask |= 1 << (c - 'a');

        bool canType = true;
        for (char c : text) {
            if (c == ' ') {
                if (canType) ans++;
                canType = true;
            } else if (brokenMask & (1 << (c - 'a'))) {
                canType = false;
            }
        }

        if (canType) ans++;
        return ans;
    }
};
