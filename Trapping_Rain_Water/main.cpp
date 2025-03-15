int trap(vector<int>& height) {
    int ans = 0;
    stack<int> stk;
    int n = height.size();
    for(int i=0; i<n; i++) {
        while(!stk.empty() && height[stk.top()] < height[i]) {
            // 第i项低洼，加水并pop掉
            int low_idx = stk.top();
            stk.pop();
            if (!stk.empty()) {
                int h = min(height[stk.top()], height[i]) - height[low_idx];
                int wide = i - stk.top() - 1;
                ans += h * wide;
            }
        }
        stk.push(i);
    }
    return ans;
}
