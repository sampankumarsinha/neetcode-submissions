class Solution {
public:
int n;
vector<vector<int>>dp;
  bool ispalindrome(int i, int j, string &s) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] = ispalindrome(i + 1, j - 1, s);
    }
    

  int solve(int i,string s){
    if(i>=n) return 0;
    int cnt=0;
    for(int idx=i;idx<n;idx++){
        if(ispalindrome(i,idx,s)) cnt++;
    }
    return cnt+solve(i+1,s);
  }
    int countSubstrings(string s) {
        n=s.length();
         dp.assign(n, vector<int>(n, -1));
        return solve(0,s);
        
    }
};
