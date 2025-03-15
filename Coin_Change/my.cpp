int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=amount; j++){
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=amount; j++){
            if (dp[i-1][j] >= 0 && j >= coins[i] && dp[i][j-coins[i]] >= 0){
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1);
            }
            else if (dp[i-1][j] >= 0){
                dp[i][j] = dp[i-1][j];
            }
            else if (j >= coins[i] && dp[i][j-coins[i]] >= 0){
                dp[i][j] = dp[i][j-coins[i]] + 1;
            }
        }
    }
	return dp[n-1][amount];
}
