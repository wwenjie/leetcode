// 法1：从前往后遍历
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    stack<int> stk;
    vector<int> res(n, -1);
    for(int i=0; i<2*n-1; i++){
        int num = nums[i % n];
        while(!stk.empty() && num > nums[stk.top()]){
            res[stk.top()] = num;
            stk.pop();
        }
        stk.push(i % n);
    }
    return res;
}

// 法2：从后往前遍历
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    stack<int> stk;
    vector<int> res(n);

    for(int i=2*n-1; i>=0; i--){
        int num = nums[i % n];
        while(!stk.empty() && num >= stk.top()){
            stk.pop();
        }
        res[i % n] = stk.empty() ? -1 : stk.top(); 
        stk.push(num);
    }
    return res;
}
