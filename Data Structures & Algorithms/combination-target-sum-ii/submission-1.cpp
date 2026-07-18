class Solution{
 public:
   vector<vector<int>>res;
  int n;
    void solve(int i,vector<int>& nums,vector<int>&temp,int target){
    if(target==0){
        res.push_back(temp);
        return;
    }
    if(target < 0)
    return;
    for(int idx=i;idx<n;idx++){
        if(idx>i && nums[idx]==nums[idx-1]) continue;
        temp.push_back(nums[idx]);
        solve(idx+1,nums,temp,target-nums[idx]);
        temp.pop_back();
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,temp,target);
        return res;
        
    }
};
