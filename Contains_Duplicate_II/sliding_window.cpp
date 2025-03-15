// 滑动窗口 + hash
// 只用uset.size()维护窗口大小
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> uset;
    for(int i=0; i<nums.size(); i++){
        if(uset.count(nums[i])){
            return true;
        }
        uset.insert(nums[i]);
        if(uset.size() > k){
            uset.erase(nums[i-k]);
        }
    }
    return false;
}


// 也是滑动窗口 + hash
// 同上的，只是改用了while循环，用start和end标记窗口
bool containsNearbyDuplicate2(vector<int>& nums, int k) {
    unordered_set<int> uset;
    int start=0, end=0;
    while(end < nums.size()){
        if(uset.find(nums[end]) != uset.end()){
            return true;
        }
        uset.insert(nums[end]);
        if (end - start == k){
            uset.erase(nums[start]);
            start++;
        }
        end++;
    }
    return false;
}
