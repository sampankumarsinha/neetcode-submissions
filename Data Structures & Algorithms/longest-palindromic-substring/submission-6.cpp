class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool ispalindrome(string &s, int i, int j) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = ispalindrome(s, i + 1, j - 1);
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        n = s.length();

        dp.assign(n, vector<int>(n, -1));

        int maxlen = 0;
        int sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (ispalindrome(s, i, j)) {

                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxlen);
    }
};