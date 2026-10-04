class Solution {
public:
 vector<vector<int>>ans;
 vector<int>temp;
 int n;
    void solve(int i,vector<int>& nums,long long target,long long currsum){
        
      if(temp.size() == 4) {
      if(currsum == target){
        ans.push_back(temp);
      }
       return;
      }
        if(i>=n) return;
        temp.push_back(nums[i]);
        solve(i+1,nums,target,currsum+nums[i]);
        temp.pop_back();
        
        int j=i+1;
        while(j<n && nums[j]==nums[i]){
            j++;
        }
        solve(j,nums,target,currsum);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n=nums.size();
        ans.clear();
    temp.clear();
    sort(nums.begin(),nums.end());
        solve(0,nums,target,0);
        return ans;
        
        }

        
    
};