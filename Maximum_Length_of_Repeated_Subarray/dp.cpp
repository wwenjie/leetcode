/*
注意不要从0->size遍历，因为dp[i][j] = dp[i-1][j-1] + 1，dp[0][0]时没有dp[-1][-1]，需要特殊处理
而size->0遍历，可以dp[i][j] = dp[i+1][j+1] + 1，且初始化vector时就可以将长度设为size+1 
*/

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int max_len = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));

    for(int i=size1-1; i>=0; i--){
        for(int j=size2-1; j>=0; j--){
            if(nums1[i] == nums2[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
                max_len = max(max_len, dp[i][j]); 
            }
        }
    }
    return max_len;
}
