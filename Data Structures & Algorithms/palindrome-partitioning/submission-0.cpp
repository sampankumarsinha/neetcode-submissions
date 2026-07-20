class Solution {
public:
    vector<vector<string>> res;
    int n;

    bool ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int idx, string &s, vector<string> &ans) {
        if (idx == n) {
            res.push_back(ans);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (ispalindrome(s, idx, i)) {
                ans.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, ans);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> ans;
        solve(0, s, ans);
        return res;
    }
};