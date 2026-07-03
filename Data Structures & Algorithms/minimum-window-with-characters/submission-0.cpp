class Solution {
public:
    // string check(string ans,string t){
    //     int n=ans.length();
    //     int i=0;
    //     while(i<n){
    //         if(ans[i]==)
    //     }
    // }
    string minWindow(string s, string t) {
       int n=s.length();
       string ans="";
       for(int i=0;i<n;i++){
        vector<int>freq(128,0);
        for(int j=i;j<n;j++){
            freq[s[j]]++;
            vector<int>temp=freq;
            bool ok=true;
            for(char c:t){
                if(temp[c]==0){
                    ok=false;
                    break;
                }
                temp[c]--;
            }
            if(ok){
                if(ans=="" ||j-i+1<ans.length()){
                    ans=s.substr(i,j-i+1);
                }
            }
        }
       }
       return ans;
        
        
    }
};
