/* 滑动窗口 */
int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0, end = 0;
    int sum = 0;
    int ans = INT_MAX;
    while(end < nums.size()){
        sum += nums[end];
        while(sum >= target){
            ans = min(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}
