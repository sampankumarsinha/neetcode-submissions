class Solution {
public:
    
         int n, m;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& vis) {
        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + drow[k];
            int nc = c + dcol[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);       // top row
            dfs(n - 1, j, heights, atlantic);  // bottom row
        }

        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);       // left column
            dfs(i, m - 1, heights, atlantic);  // right column
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};