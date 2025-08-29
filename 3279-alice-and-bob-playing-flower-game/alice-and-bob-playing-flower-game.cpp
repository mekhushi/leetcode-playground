class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenRows = n / 2;
        long long evenCols = m / 2;
        long long oddRows = n - evenRows;
        long long oddCols = m - evenCols;

        return evenRows * oddCols + evenCols * oddRows;
    }
};
