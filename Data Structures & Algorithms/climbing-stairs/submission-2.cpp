#include<cstring>
class Solution {
public:
   int dp[46];
   int solve(int steps,int n){
    if(steps==n) return 1;
    if(steps>n) return 0;
    if(dp[steps]!=-1) return dp[steps];
    int s1=solve(steps+1,n);
    int s2=solve(steps+2,n);
    return dp[steps]=s1+s2;
   }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        
    return solve(0,n);
        
    }
};
