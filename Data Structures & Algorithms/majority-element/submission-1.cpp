class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        int maxi=0;
        int ans;
        
        for(auto &it:mpp){
            if(it.second>maxi){
            maxi=max(maxi,it.second);
            ans=it.first;
            }
        }
        return ans;
        
    }
};