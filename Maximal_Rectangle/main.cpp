int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> heights(m, vector<int>(n, 0));

    for(int j=0; j<n; j++)
        heights[0][j] = matrix[0][j] == '1' ? 1 : 0;
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if (matrix[i][j] == '1'){
                heights[i][j] = heights[i-1][j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        vector<int> left(n);
        vector<int> right(n, n); // 默认值n表示右边的值都大于heights[i][j]
        stack<int> stk; // 保持递增

        // 找左边界，左边第一个比heights[i][j]小的下标
        for(int j=0; j<n; j++){
            while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]){
                stk.pop();
            }
            left[j] = stk.empty() ? -1 : stk.top();
            stk.push(j);
        }

        // 找右边界，右边第一个比heights[i][j]小的下标
        stk = stack<int>();
        for(int j=0; j<n; j++){
            while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]){
                right[stk.top()] = j;
                stk.pop();
            }
            stk.push(j);
        }
        for(int j=0; j<n; j++){
            int wide = right[j] - left[j] - 1;
            int h = heights[i][j];
            ans = max(ans, h * wide);
        }
    }
    return ans;
}

