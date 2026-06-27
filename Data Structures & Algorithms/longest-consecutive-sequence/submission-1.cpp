class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int maxlen=1;
        int len=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            else if(abs(nums[i]-nums[i-1])==1) len++;
            else{
                len=1;
                }
            maxlen=max(maxlen,len);
        }
        return maxlen;
        
    }
};
