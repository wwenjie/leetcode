class NumArray {

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n <= 0)
            return;
        this->nums = nums;
        // 问：为啥4*n，为啥不是4*(nums中最大值)
        // 答：看输入和输出示例
        seg_tree.resize(4 * n);
        _build(1, 0, n-1);
    }

    void update(int index, int val) {
        _update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return _sumRange(1, 0, n-1, left, right);
    }
private:
    vector<int> seg_tree;
    vector<int> nums;
    int n;
    void _build(int s_idx, int l, int r){
        if(l == r){
            seg_tree[s_idx] = nums[r];
            return;
        }
        int left = 2 * s_idx;
        int right = 2 * s_idx + 1;
        int mid = (l + r) >> 1;
        _build(left, l, mid);
        _build(right, mid+1, r);
        seg_tree[s_idx] = seg_tree[left] + seg_tree[right];
    }
    void _update(int s_idx, int l, int r, int index, int val){
        if(l == r && l == index){
            seg_tree[s_idx] = val;
            return;
        }
        int left = 2 * s_idx;
        int right = 2 * s_idx + 1;
        int mid = (l + r) >> 1;
        if (index <= mid)
            _update(left, l, mid, index, val);
        else
            _update(right, mid+1, r, index, val);
        seg_tree[s_idx] = seg_tree[left] + seg_tree[right];
    }
    int _sumRange(int s_idx, int l, int r, int left, int right){
        if(left == l && right == r)
            return seg_tree[s_idx];
        int s_left = 2 * s_idx;
        int s_right = 2 * s_idx + 1;
        int mid = (l + r) >> 1;
        if(right <= mid)
            return _sumRange(s_left, l, mid, left, right);
        else if(left > mid)
            return _sumRange(s_right, mid+1, r, left, right);
        else
            return _sumRange(s_left, l, mid, left, mid) + 
                    _sumRange(s_right, mid+1, r, mid+1, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
