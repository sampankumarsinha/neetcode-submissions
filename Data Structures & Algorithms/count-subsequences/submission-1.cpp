#include<cstring>
class Solution {
public:
int dp[1001][1001];
    int n,m;
    int solve(int i,int j,string s,string t,string curr){
        if(j==m) return 1;
        if(i==n) return 0;
        if(curr==t) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0,not_take=0;
        if(s[i]==t[j]){
      take=solve(i+1,j+1,s,t,curr);
        }
        
        
        not_take=solve(i+1,j,s,t,curr);
        return dp[i][j]=take+not_take;


    }
    int numDistinct(string s, string t) {
        n=s.length();
        m=t.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t,"");
    
        
    }
};
