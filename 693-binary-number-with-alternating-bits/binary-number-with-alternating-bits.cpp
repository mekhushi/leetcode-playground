class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n % 2;   // store last bit
        n = n / 2;

        while (n > 0) {
            int curr = n % 2;   // current bit
            
            if (curr == prev) {
                return false;   // two same bits found
            }

            prev = curr;       // update previous bit
            n = n / 2;
        }

        return true;
    }
};
