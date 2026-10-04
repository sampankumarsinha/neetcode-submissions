class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int mini=INT_MAX;
        while(r<n){
           
            while(r<n && sum<target){
                sum+=nums[r];
                r++;
            }
            while(sum>=target){
                mini=min(mini,r-l);
                sum-=nums[l];
                l++;
            }
            
           
            }
            return mini==INT_MAX ? 0:mini;
            
        
        
    }
};