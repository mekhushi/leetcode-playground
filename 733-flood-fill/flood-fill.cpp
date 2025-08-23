class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor) dfs(image, sr, sc, oldColor, newColor);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oldColor)
            return;
        image[i][j] = newColor;
        dfs(image,i+1,j,oldColor,newColor);
        dfs(image,i-1,j,oldColor,newColor);
        dfs(image,i,j+1,oldColor,newColor);
        dfs(image,i,j-1,oldColor,newColor);
    }
};
