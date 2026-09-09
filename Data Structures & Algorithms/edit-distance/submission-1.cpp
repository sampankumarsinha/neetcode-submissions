#include<cstring>
class Solution {
public:
int dp[101][101];
   int n,m;
   int solve(int i,int j,string &word1,string &word2){
    if(i==n) return m-j;
    if(j==m) return n-i;
    if(dp[i][j]!=-1) return dp[i][j];
    
   int take=0;
    if(word1[i]==word2[j]){
         return dp[i][j]=solve(i+1,j+1,word1,word2);
    }
    int insert=1+solve(i,j+1,word1,word2);
    int delete_i=1+solve(i+1,j,word1,word2);
    int replace=1+solve(i+1,j+1,word1,word2);
    return dp[i][j]=min({insert,delete_i,replace});

   }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        n=word1.length();
        m=word2.length();
        return solve(0,0,word1,word2);

        
    }
};
