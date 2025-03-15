// 法4：单调栈，跟3一样，3清晰点
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n); // 左边第一个比height[i]小的下标
    vector<int> right(n); // 右边第一个比height[i]小的下标
    stack<int> stk; // 递增
    for(int i=0; i<n; i++){
        int h = heights[i];
        while(!stk.empty() && heights[stk.top()] >= h){
            right[stk.top()] = i;
            stk.pop();
        }
        left[i] = stk.empty() ? -1 : stk.top(); // -1是左边的边界，表示左边没有比heights[i]小的项
        right[i] = n; // n是右边的边界，表示右边没有比heights[i]小的项，或者前面初始化时right(n,n)
        stk.push(i);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int h = heights[i];
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
}
// 法3：单调栈
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n); // 左边第一个比height[i]小的下标
    vector<int> right(n); // 右边第一个比height[i]小的下标
    stack<int> stk; // 递增
    for(int i=0; i<n; i++){
        int h = heights[i];
        while(!stk.empty() && heights[stk.top()] >= h){
            stk.pop();
        }
        left[i] = stk.empty() ? -1 : stk.top(); // -1是左边的边界，表示左边没有比heights[i]小的项
        stk.push(i);
    }
    stk = stack<int>(); // 递增
    for(int i=0; i<n; i++){
        int h = heights[i];
        while(!stk.empty() && heights[stk.top()] >= h){
            right[stk.top()] = i;
            stk.pop();
        }
        right[i] = n; // n是右边的边界，表示右边没有比heights[i]小的项
        stk.push(i);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int h = heights[i];
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
}

// 法2：枚举高度，再找左右边界，超时
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        int h = heights[i];
        int left = i;
        int right = i;
        while(left-1 >= 0 && heights[left-1] >= heights[i]){
            left--;
        }
        while(right+1 < n && heights[i] <= heights[right+1]){
            right++;
        }
        ans = max(ans, (right - left + 1) * h);
    }
    return ans;
}

// 法1：枚举左右边界，再找高度，超时
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int res = 0;
    for(int left=0; left<n; left++){
        int min_height = heights[left];
        for(int right=left; right<n; right++){
            min_height = min(min_height, heights[right]);
            res = max(res, min_height * (right - left + 1));
        }
    }
    return res;
}
