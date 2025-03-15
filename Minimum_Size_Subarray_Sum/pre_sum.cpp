/* 
    前缀和 + 二分查找 
    只有保证nums每个数都是正的，才能保证单调pre_sum单调性，才能用二分查找
    lower_bound 是c++提供的二分查找函数>=某个数的第一个位置
*/
int minSubArrayLen(int target, vector<int>& nums) {
    int size = nums.size();
    vector<int> pre_sum(size+1);
    pre_sum[0] = 0;
    for(int i=1; i<=size; i++){
        pre_sum[i] = pre_sum[i-1] + nums[i-1];
    }
    if (pre_sum[size] < target)
        return 0;
    int ans = INT_MAX;
    for(int i=1; i<=size; i++) {
        int tmp = target + pre_sum[i-1];
        vector<int>::iterator it = lower_bound(pre_sum.begin(), pre_sum.end(), tmp);
        if (it != pre_sum.end() ){
            ans = min(ans, static_cast<int>(it - pre_sum.begin()) - (i-1) );
        }
    }

    return ans == INT_MAX ? 0 : ans;
}
