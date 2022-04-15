class Solution {
public:

    //based on optimal strategy of a game
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        int dp[n][n];

        int sum = accumulate(piles.begin(), piles.end(), 0);
        memset(dp, 0, sizeof(dp));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                    dp[i][j] = piles[i];
                else if (gap == 1)
                    dp[i][j] = max(piles[i], piles[j]);
                else
                {
                    int val1 = piles[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                    int val2 = piles[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        if (dp[0][n - 1] > (sum - dp[0][n - 1]))
            return true;
        return false;

    }
};