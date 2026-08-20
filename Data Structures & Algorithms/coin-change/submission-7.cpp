class Solution {
public:
    int n;
    int mini = INT_MAX;
    vector<vector<int>> dp;

    void solve(int i, vector<int>& coins, int amount, int sum, int cnt) {
     if (sum > amount || i >= n)
        return;

    if (cnt >= mini)
        return;

    if (sum == amount) {
        mini = min(mini, cnt);
        return;
    }

    if (dp[i][sum] != -1 && dp[i][sum] <= cnt)
        return;

    dp[i][sum] = cnt;

    solve(i, coins, amount, sum + coins[i], cnt + 1);
    solve(i + 1, coins, amount, sum, cnt);
}
    

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        if (amount == 0)
            return 0;

        mini = INT_MAX;  // reset

        dp.assign(n, vector<int>(amount + 1, -1));

        solve(0, coins, amount, 0, 0);

        return mini == INT_MAX ? -1 : mini;
    }
};