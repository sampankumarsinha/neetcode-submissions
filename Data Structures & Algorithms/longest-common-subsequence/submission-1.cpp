#include<cstring>
class Solution {
public:
int maxi=INT_MIN;
int n;
int m;
int dp[1001][1001];
    int solve(int i,int j,string text1,string text2){
        if(i>=n) return 0;
        if(j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,not_take=0,skip=0;
        if(text1[i]==text2[j]){
            take=1+solve(i+1,j+1,text1,text2);
            
        }
        not_take=solve(i,j+1,text1,text2);
        skip=solve(i+1,j,text1,text2);
        return dp[i][j]=max(take,max(not_take,skip));


    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);

        
        
    }
};
