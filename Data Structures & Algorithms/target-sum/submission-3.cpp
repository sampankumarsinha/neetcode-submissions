#include<cstring>
class Solution {
public:
    int dp[21][1001];
    int n;
    int solve(int i,vector<int>&nums,int target){
        if (i == n) {
            return target == 0;
        }
        int idx=1000+target;
        if(dp[i][idx]!=-1) return dp[i][idx];
         int take=solve(i+1,nums,target-nums[i]);
         int not_take=solve(i+1,nums,target+nums[i]);
         return dp[i][idx]=take+not_take;
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,target);
        
        
        
    }
};
