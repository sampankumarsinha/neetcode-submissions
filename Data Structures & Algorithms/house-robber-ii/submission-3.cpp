#include<cstring>
class Solution{
public:

int n;
int dp[201];

int solve(int i, int end, vector<int>& nums) {
    if (i > end){
        return 0;
}
    if(dp[i]!=-1) return dp[i];

    int take = nums[i] + solve(i + 2, end, nums);
    int skip = solve(i + 1, end, nums);

    return dp[i]=max(take, skip);
}

int rob(vector<int>& nums) {
    n = nums.size();
    memset(dp,-1,sizeof(dp));

    if (n == 1)
        return nums[0];

    int case1 = solve(0, n - 2, nums); // include house 0
     memset(dp,-1,sizeof(dp));
    int case2 = solve(1, n - 1, nums); // exclude house 0

    return max(case1, case2);
}
};