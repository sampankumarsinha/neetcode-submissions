class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int area = 1;
        area += dfs(r + 1, c, grid);
        area += dfs(r - 1, c, grid);
        area += dfs(r, c + 1, grid);
        area += dfs(r, c - 1, grid);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
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