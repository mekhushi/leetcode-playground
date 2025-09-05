class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long ops = 1; ops <= 60; ++ops) {
            long target = num1 - ops * num2;
            if (target < 0) break;
            if (__builtin_popcountl(target) <= ops && ops <= target)
                return ops;
        }
        return -1;
    }
};
