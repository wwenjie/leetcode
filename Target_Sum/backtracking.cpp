// 回溯,dps
int findTargetSumWays(vector<int>& nums, int target) {
    return cal(nums, target, 0, 0);
}

int cal(vector<int>& nums, int target, int sum, int idx){
    if (idx == nums.size()){
        return target == sum ? 1 : 0;
    }
    return cal(nums, target, sum + nums[idx], idx+1) + cal(nums, target    , sum - nums[idx], idx+1);
}

