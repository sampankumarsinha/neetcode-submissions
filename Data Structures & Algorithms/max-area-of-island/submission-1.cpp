#include<cstring>
class Solution {
public:
  int dp[51][51];

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        grid[r][c] = 0;
        int area = 1;
        area += dfs(r + 1, c, grid);
        area += dfs(r - 1, c, grid);
        area += dfs(r, c + 1, grid);
        area += dfs(r, c - 1, grid);
        return dp[r][c]=area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    max_cnt = max(max_cnt, dfs(i, j, grid));
                }
            }
        }
        return max_cnt;
    }
};