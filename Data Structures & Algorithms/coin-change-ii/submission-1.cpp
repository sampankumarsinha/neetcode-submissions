#include<cstring>
class Solution {
public:
    int n;
    int dp[101][5001];
    int solve(int i,vector<int>&nums,int amount){
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(i>=n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=solve(i,nums,amount-nums[i]);
        int not_take=solve(i+1,nums,amount);
        return dp[i][amount]=(take+not_take);
    }
    int change(int amount, vector<int>& coins) {
         n=coins.size();
         memset(dp,-1,sizeof(dp));
          return solve(0,coins,amount);
        
    }
};
