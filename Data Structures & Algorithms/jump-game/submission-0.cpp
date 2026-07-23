class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k=nums.size()-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=k){
                k=i;
            }

            
        }
        return k==0?true:false;
        
    }
};
