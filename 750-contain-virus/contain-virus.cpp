class Solution {
public:
    int containVirus(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), total=0;
        vector<pair<int,int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        
        while (true) {
            vector<vector<int>> seen(m, vector<int>(n,0));
            vector<vector<pair<int,int>>> regions;
            vector<unordered_set<int>> frontiers;
            vector<int> walls;

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(g[i][j]==1 && !seen[i][j]){
                        queue<pair<int,int>> q; q.push({i,j}); seen[i][j]=1;
                        vector<pair<int,int>> region; unordered_set<int> frontier;
                        int w=0;
                        while(!q.empty()){
                            auto [x,y]=q.front(); q.pop();
                            region.push_back({x,y});
                            for(auto &[dx,dy]:dirs){
                                int nx=x+dx, ny=y+dy;
                                if(nx>=0 && nx<m && ny>=0 && ny<n){
                                    if(g[nx][ny]==1 && !seen[nx][ny]) {seen[nx][ny]=1;q.push({nx,ny});}
                                    else if(g[nx][ny]==0){frontier.insert(nx*n+ny); w++;}
                                }
                            }
                        }
                        regions.push_back(region);
                        frontiers.push_back(frontier);
                        walls.push_back(w);
                    }
                }
            }
            if(regions.empty()) break;
            int idx=max_element(frontiers.begin(), frontiers.end(), 
                                [](auto &a, auto &b){return a.size()<b.size();}) - frontiers.begin();
            total+=walls[idx];
            for(auto &[x,y]:regions[idx]) g[x][y]=-1;
            for(int k=0;k<regions.size();k++){
                if(k==idx) continue;
                for(auto id:frontiers[k]) g[id/n][id%n]=1;
            }
        }
        return total;
    }
};
