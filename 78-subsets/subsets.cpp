class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& n) {
    vector<vector<int>> a;
    f(n,0,{},a);
    return a;
  }
 private:
  void f(vector<int>& n,int s,vector<int> p,vector<vector<int>>& a){
    a.push_back(p);
    for(int i=s;i<n.size();p.pop_back())
      p.push_back(n[i]),f(n,++i,p,a);
  }
};