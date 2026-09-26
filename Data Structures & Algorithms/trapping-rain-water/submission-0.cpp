class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
        int i=0;
        int j=n-1;
        int leftmax=height[i];
        int rightmax=height[j];
        int water=0;
        while(i<j){
        if(leftmax<rightmax){
            i++;
            leftmax=max(leftmax,height[i]);
            water+=leftmax-height[i];

        }else{
            j--;
            rightmax=max(rightmax,height[j]);
            water+=rightmax-height[j];
        }
        }
        return water;
        

        
    }
};
