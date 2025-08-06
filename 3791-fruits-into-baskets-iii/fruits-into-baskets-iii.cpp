class SegmentTree {
 public:
  SegmentTree(vector<int>& a) : n(a.size()), t(n * 4) { build(a, 0, 0, n - 1); }
  int queryFirst(int x) { return query(0, 0, n - 1, x); }
 private:
  int n; vector<int> t;
  void build(vector<int>& a, int i, int l, int r) {
    if (l == r) { t[i] = a[l]; return; }
    int m = (l + r) / 2;
    build(a, i*2+1, l, m); build(a, i*2+2, m+1, r);
    t[i] = max(t[i*2+1], t[i*2+2]);
  }
  void upd(int i, int l, int r, int p, int v) {
    if (l == r) { t[i] = v; return; }
    int m = (l + r) / 2;
    (p <= m) ? upd(i*2+1, l, m, p, v) : upd(i*2+2, m+1, r, p, v);
    t[i] = max(t[i*2+1], t[i*2+2]);
  }
  int query(int i, int l, int r, int x) {
    if (t[i] < x) return -1;
    if (l == r) { upd(0, 0, n - 1, l, -1); return l; }
    int m = (l + r) / 2;
    return t[i*2+1] >= x ? query(i*2+1, l, m, x) : query(i*2+2, m+1, r, x);
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
    int ans = 0; SegmentTree st(b);
    for (int x : f) ans += (st.queryFirst(x) == -1);
    return ans;
  }
};
