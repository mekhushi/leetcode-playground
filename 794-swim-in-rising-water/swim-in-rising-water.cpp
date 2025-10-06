class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
        int n = g.size(), ans = 0;
        vector<vector<bool>> seen(n, vector<bool>(n,0));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({g[0][0], {0,0}});
        seen[0][0] = 1;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(pq.size()){
            auto [h, p] = pq.top(); pq.pop();
            ans = max(ans, h);
            int i=p.first, j=p.second;
            if(i==n-1 && j==n-1) break;
            for(auto &d: dirs){
                int x=i+d[0], y=j+d[1];
                if(x>=0 && x<n && y>=0 && y<n && !seen[x][y]){
                    pq.push({g[x][y], {x,y}});
                    seen[x][y]=1;
                }
            }
        }
        return ans;
    }
};
