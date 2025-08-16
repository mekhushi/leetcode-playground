class Solution {
public:
    int maximum69Number (int num) {
        int temp = num, pos = -1, i = 0;
        while (temp > 0) {
            if (temp % 10 == 6) pos = i;
            temp /= 10;
            i++;
        }
        if (pos == -1) return num;
        return num + 3 * static_cast<int>(pow(10, pos));
    }
};
