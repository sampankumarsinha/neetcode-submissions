class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int ans=0;
        int l=0;
        int r=0;
        int n=s.length();
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(mpp[s[l]]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};
