class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=0;
        int k=0;
        for(int i=0;i<n;i++){
            
            while(j<n && nums[j]==val){
                j++;
            }
            if(j>=n) break;
            nums[i]=nums[j];
            j++;
            k++;
        }
        return k;
       
        
        
        
    }
};