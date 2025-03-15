
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    else if (n == 2)
        return max(nums[0], nums[1]);
    return max(robRange1(nums, 0, n-2), robRange2(nums, 1, n-1));
}

// 普通dp
int robRange1(vector<int>& nums, int start, int end) {
    int size = end - start + 1;
    vector<int> dp(size);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start+1]);
    
    for(int i=2; i<size; i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[start+i]);
    }
    return dp[dp.size()-1];
}

// dp + 滚动数组
int robRange(vector<int>& nums, int start, int end) {
    int first = nums[start];
    int second = max(nums[start], nums[start+1]);
    int temp;
    
    for(int i=start+2; i<=end; i++){
        temp = max(second, first + nums[i]);
        first = second;
        second = temp;
    }
    return second;
}
