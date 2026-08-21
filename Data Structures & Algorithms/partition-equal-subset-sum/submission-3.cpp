#include<cstring>
class Solution {
public:
   int n;
   vector<vector<int>>dp;
   bool solve(int i,vector<int>&nums,int target,int currsum){
    if(i>=n) return false;
    if(currsum==target) return true;
    if(currsum>target) return false;
    if(dp[i][currsum]!=-1) return dp[i][currsum];
    
    bool take=solve(i+1,nums,target,currsum+nums[i]);
    bool not_take=solve(i+1,nums,target,currsum);
    return dp[i][currsum]=take|| not_take;
   }
    bool canPartition(vector<int>& nums) {
     int totalsum=0;
     n=nums.size();
     for(int i:nums){
        totalsum+=i;
     }
    
     if(totalsum%2!=0) return false;
     int s1=totalsum/2;
     int target=s1;
     dp.resize(n+1,vector<int>(target+1,-1));
     return solve(0,nums,target,0);

        
    }
};
