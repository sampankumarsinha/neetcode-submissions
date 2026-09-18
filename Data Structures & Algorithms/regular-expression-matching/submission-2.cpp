#include<cstring>
class Solution {
public:
    int dp[21][21];

    bool solve(string s,string p){
    if(p.length()==0){
    return s.length()==0;
        }
        if(dp[s.length()][p.length()]!=-1) return dp[s.length()][p.length()];
        
    bool can=false;
    if(s.length()>0 && (p[0]==s[0] || p[0]=='.')){
        can=true;
    }
    if(p[1]=='*'){
        bool take= can && solve(s.substr(1),p);
        bool not_take=solve(s,p.substr(2));
        return dp[s.length()][p.length()]=not_take|| take;
    }
        return dp[s.length()][p.length()]=can && solve(s.substr(1),p.substr(1));
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s,p);
        }
};