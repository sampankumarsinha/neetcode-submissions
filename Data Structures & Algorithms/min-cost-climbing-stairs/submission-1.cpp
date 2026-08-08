#include<cstring>
class Solution {
public:
int n;
int dp[101];
  int solve(int i,vector<int>&cost){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int s1=cost[i]+solve(i+1,cost);
    int s2=cost[i]+solve(i+2,cost);
    return dp[i]=min(s1,s2);
  }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        int ans1=solve(0,cost);
        int ans2=solve(1,cost);
        return min(ans1,ans2);
        
    }
};
