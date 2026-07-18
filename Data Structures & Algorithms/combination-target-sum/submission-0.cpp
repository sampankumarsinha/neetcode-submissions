class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(int i,vector<int>&nums,int sum,int target,vector<int>&temp){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target || i>=n) return;
        temp.push_back(nums[i]);
        solve(i,nums,sum+nums[i],target,temp);
        temp.pop_back();
        solve(i+1,nums,sum,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        vector<int>temp;
        solve(0,nums,0,target,temp);
        return ans;
        
    }
};
