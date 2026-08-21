#include<cstring>

class Solution {
public:
   int n;
   int dp[1001][1001];
    int solve(int i,int j,vector<int>&nums){
        if( i>=n || j>=n) return 0;
        if(dp[i+1][j]!=-1) return dp[i+1][j];
        int take=0,not_take=0;
        if( i==-1 || nums[j]>nums[i]){
            take=1+solve(j,j+1,nums);
        }
            not_take=solve(i,j+1,nums);
        
        return dp[i+1][j]=max(take,not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
       n=nums.size();
       memset(dp,-1,sizeof(dp));
      return solve(-1,0,nums);

        
    }
};
