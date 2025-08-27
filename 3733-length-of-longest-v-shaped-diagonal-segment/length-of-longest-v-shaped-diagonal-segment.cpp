#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{-1,1},{1,1},{1,-1},{-1,-1}};
        int res = 0;

        vector<vector<vector<vector<int>>>> mem(
            m, vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(4,-1)))
        );

        function<int(int,int,int,bool,int)> dfs = [&](int i,int j,int num,bool turned,int d) {
            if(i<0||i>=m||j<0||j>=n||grid[i][j]!=num) return 0;
            if(mem[i][j][turned][d]!=-1) return mem[i][j][turned][d];

            int nextNum = (num==2?0:2);
            int ni = i+dirs[d][0], nj = j+dirs[d][1];
            int ans = 1 + dfs(ni,nj,nextNum,turned,d);

            if(!turned) {
                int nd = (d+1)%4;  // only one 90° turn
                int ni2 = i + dirs[nd][0], nj2 = j + dirs[nd][1];
                if(ni2>=0 && ni2<m && nj2>=0 && nj2<n && grid[ni2][nj2]==nextNum)
                    ans = max(ans, 1 + dfs(ni2,nj2,nextNum,true,nd));
            }

            return mem[i][j][turned][d] = ans;
        };

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    for(int d=0;d<4;d++)
                        res = max(res, dfs(i,j,1,false,d));

        return res;
    }
};
