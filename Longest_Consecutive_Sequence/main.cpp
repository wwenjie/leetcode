int longestConsecutive(vector<int>& nums) {
    int longest_cnt = 0;
    unordered_set<int> num_set;
    for(const int& num: nums) {
        num_set.insert(num);
    }

    for(const int& num: num_set){
        // 任何序列[1..n]中1~n-1的数不进行内层循环遍历，保证复杂度O(n)
        if(num_set.count(num+1))
            continue;
        int cur_num = num;
        int cur_cnt = 1;
        while(num_set.count(cur_num - 1)) {
            cur_num--;
            cur_cnt++;
        }
        longest_cnt = max(longest_cnt, cur_cnt);
    }
    return longest_cnt;
}
