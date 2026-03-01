class Solution {
public:
    int minPartitions(string s) {
        int hDigit = 0;

        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            if (digit > hDigit) {
                hDigit = digit;
            }
        }

        return hDigit;
    }
};