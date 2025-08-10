#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    static const unordered_set<int> sigs = pre();
    return sigs.count(cnt(n));
  }

 private:
  static int cnt(int n) {
    static const int p10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int c = 0;
    while (n) { c += p10[n % 10]; n /= 10; }
    return c;
  }

  static unordered_set<int> pre() {
    unordered_set<int> s;
    for (int i = 0; i < 31; ++i) s.insert(cnt(1 << i));
    return s;
  }
};
