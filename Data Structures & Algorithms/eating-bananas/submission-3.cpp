class Solution {
public:
    bool check(vector<int>& piles,int mid,int h){
        int n=piles.size();
        int ans=0;
           for(int i=0;i<n;i++){
             ans+=ceil((double)piles[i]/mid);
           }
           return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=high){
            int mid=l+(high-l)/2;
            if(check(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
               l=mid+1;
            }

            
        }
        return ans;

        
    }
};
