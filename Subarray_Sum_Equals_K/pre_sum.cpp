int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1; //这里有玄机！！！前缀和pre_sum刚好为k的情况没有统计到
    int cnt = 0;
    int pre_sum = 0; //前缀和
    for(int num: nums){
        pre_sum += num;
        if(mp.find(pre_sum - k) != mp.end()){
            // 前面存在pre_sum-k的前缀和，说明存在连续子数组和为k
            cnt += mp[pre_sum - k];
        }
        mp[pre_sum]++;
    }
    return cnt;
}
