class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = s[0] == s[n - 1];
        for (int i = 1; i < n; i++)
            dp[0][i] = max((int) (s[0] == s[n - 1 - i]), dp[0][i - 1]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) {
                    if (s[i] == s[n - 1 - j]) {
                        dp[1][j] = 1 + dp[0][j - 1];
                    } else {
                        dp[1][j] = max(dp[0][j], dp[1][j - 1]);
                    }
                } else {
                    dp[1][j] = max((int) (s[i] == s[n - 1]), dp[0][j]);
                }
            }
            dp[0] = dp[1];
        }
        return (n - dp[0].back());
    }
};