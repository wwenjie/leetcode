int findLength(vector<int>& nums1, vector<int>& nums2) {
    int max_len = 0;
    int len1 = nums1.size();
    int len2 = nums2.size();
    for(int i=0; i<len1; i++){
        int len = min(len1-i, len2);
        int temp = maxLen(nums1, nums2, i, 0, len);
        max_len = max(temp, max_len);
    }
    for(int i=0; i<len2; i++){
        int len = min(len2-i, len1);
        int temp = maxLen(nums1, nums2, 0, i, len);
        max_len = max(temp, max_len);
    }
    return max_len;
}

int maxLen(vector<int>& nums1, vector<int>& nums2, int add1, int add2, int len){
    // len是重合的长度
    int max_len = 0, k=0;
    for(int i=0; i<len; i++){
        if(nums1[add1 + i] == nums2[add2 + i]) {
            k++;
            max_len = max(max_len, k);
        }
        else {
            k = 0;
        }
    }
    return max_len;
}
