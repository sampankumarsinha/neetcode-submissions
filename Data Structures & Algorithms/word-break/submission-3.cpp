
#include<cstring>
class Solution {
public:
int n;
int dp[201];
    bool solve(int i,string s,unordered_set<string>&st){
     if(i>=n) return true;
     if(dp[i]!=-1) return dp[i];
     
      
      if(st.find(s)!=st.end()) return dp[i]=true;
      for(int idx=1;idx<=n;idx++){
        string temp=s.substr(i,idx);
        if(st.find(temp) !=st.end() && solve(i+idx,s,st)) return      dp[i]=true;
      }
      return dp[i]=false;
    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        unordered_set<string>st(wordDict.begin(),wordDict.end());
       
         return solve(0,s,st);

        
    }
};
