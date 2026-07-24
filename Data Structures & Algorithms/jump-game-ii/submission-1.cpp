class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        
        int totaljumps=0;
        int startidx=0;
        int maxidx=0;
        for(int i=0;i<n;i++){
            startidx=max(startidx,i+nums[i]);
            if(i==maxidx){
                maxidx=startidx;
                totaljumps++;
            
            if(startidx>=n-1){
                break;
            }
        }
        }
        return totaljumps;

        
    }
};
