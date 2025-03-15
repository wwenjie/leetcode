/*
dp[i][j]表示前i个数经过计算等于j的方案数
j < nums[i], dp[i][j] = dp[i-1][j]
j >=nums[i], dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j]
*/
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for(int& num: nums)
        sum += num;
    int diff = sum - target;
    if (diff < 0) // || diff % 2 != 0 这个怎么说？
        return 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<=target; j++){
            if (j < nums[i]){
                dp[i][j] = dp[i-1][j]
            }
            else {
                dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j];
            }
        }
    }
    return dp[i][j];
}
