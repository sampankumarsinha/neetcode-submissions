class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        vector<int>ans;
        for(int j=i+1;j<n;j++){
            if(nums[j]!=nums[i]){
                 i++;
                nums[i]=nums[j];
                
              
            }
        }
        return i+1;
        
    }
};