#include<cstring>
class Solution {
public:
    int dp[101][101];
     bool solve(int i,int j,int k,string s1,string s2,string s3,string ans){
       if(k==s3.size()){
        return (i==s1.size() && j==s2.size());
       }
       if(dp[i][j]!=-1) return dp[i][j];
       
       bool take=false;
       bool skip=false;
if(i<s1.size() && s1[i]==s3[k]){
             take=solve(i+1,j,k+1,s1,s2,s3,ans);
       }
      
    if(j<s2.size() && s2[j]==s3[k]){
         skip=solve(i,j+1,k+1,s1,s2,s3,ans);
       }
   return dp[i][j]=take || skip;
       }
bool isInterleave(string s1, string s2, string s3) {
    memset(dp,-1,sizeof(dp));
        
        return solve(0,0,0,s1,s2,s3,"");

        
    }
};
