#include<cstring>
class Solution {
public:
int dp[101][101];
   bool solve(int i,string s,int open){
    if(i==s.length()){
        return open==0;
    }
    if(dp[i][open]!=-1) return dp[i][open];
    bool isvalid=false;
    
    if(s[i]=='('){
        isvalid |=solve(i+1,s,open+1);
    }else if(s[i]=='*'){
        isvalid|=solve(i+1,s,open);
        isvalid|=solve(i+1,s,open+1);
        if(open>0) isvalid |=solve(i+1,s,open-1);
    }else if(open>0){
        isvalid|=solve(i+1,s,open-1);
    }
    return dp[i][open]=isvalid;
        
    }
   
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
      return solve(0,s,0);        
    }
};