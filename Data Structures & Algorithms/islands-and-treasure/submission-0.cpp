class Solution {
public:
 int n, m;
    int INF = INT_MAX;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>>& grid, int dist) {
        if(r < 0 || r >= n || c < 0 || c >= m) return;

        // If current cell already has smaller distance, no need to continue
        if(grid[r][c] < dist) return;

        grid[r][c] = dist;

        for(int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            dfs(nrow, ncol, grid, dist + 1);
        }
    }
  
   
    void islandsAndTreasure(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid,cnt);
                }
            }
        }
        
        
        
        
    }
};
