class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }
        vector<int>ans;
       int i=0;
       while(i<n){
        int end=mpp[s[i]];
        int j=i;
        while(j<end){
            end=max(end,mpp[s[j]]);
            j++;
        }
        ans.push_back(j-i+1);
        i=j+1;
       } 
       return ans;

    
    
    
    }


        
    
    
};
