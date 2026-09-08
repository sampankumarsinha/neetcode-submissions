#include<cstring>
class Solution {
public:
   int n,m;
   int dp[101][101];
    int solve(int i,int j,vector<vector<int>>& matrix,int prev){
        if(i<0 || j<0 || i>=n || j>=m || matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+max({solve(i+1,j,matrix,matrix[i][j]),solve(i,j+1,matrix,matrix[i][j]),solve(i,j-1,matrix,matrix[i][j]),solve(i-1,j,matrix,matrix[i][j])});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,solve(i,j,matrix,-1));
            }
        }
        return maxi;
        
    }
};
