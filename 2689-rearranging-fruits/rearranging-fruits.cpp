#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int, int> m;
        vector<int> swap;

        for (int x : b1) ++m[x];
        for (int x : b2) --m[x];

        for (auto& [k, v] : m) {
            if (v % 2) return -1;
            for (int i = 0; i < abs(v) / 2; ++i) swap.push_back(k);
        }

        if (swap.empty()) return 0;

        int mn = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));
        nth_element(swap.begin(), swap.begin() + swap.size() / 2, swap.end());

        long long res = 0;
        for (int i = 0; i < swap.size() / 2; ++i)
            res += min(2 * mn, swap[i]);

        return res;
    }
};
