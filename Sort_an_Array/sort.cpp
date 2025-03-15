vector<int> tmp;

vector<int> sortArray2(vector<int>& nums) {
    tmp.resize(nums.size(), 0);
    mergeSort(nums, 0, nums.size()-1);
    return nums;
}

void mergeSort(vector<int>& nums, int l, int r){
    if (l >= r)
        return;
    int mid = (l + r) >> 1; // 右移1位相当于除2
    mergeSort(nums, l, mid);
    mergeSort(nums, mid+1, r);
    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r) {
        if(nums[i] < nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    while(i <= mid)
        tmp[k++] = nums[i++];
    while(j <= r)
        tmp[k++] = nums[j++];
    for(int i=0; i<k; i++){
        nums[i+l] = tmp[i];
    }
}
