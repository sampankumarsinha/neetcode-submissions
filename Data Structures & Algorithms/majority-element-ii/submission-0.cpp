class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cutoff=n/3;
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        vector<int>ans;
        int i=0;
        for(auto &it:mpp){
            if(it.second>cutoff){
                ans.push_back(it.first);
                
            }
        }
        return ans;
        
    }
};