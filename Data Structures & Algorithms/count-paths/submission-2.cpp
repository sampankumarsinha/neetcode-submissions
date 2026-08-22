#include<cstring>
class Solution {
public:
int cnt=0;
int dp[101][101];
  int solve(int i,int j,int m,int n){
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    
    
    int take=solve(i+1,j,m,n);
    int not_take=solve(i,j+1,m,n);
    return dp[i][j]=(take+not_take);
    
  }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
        
    }
};
