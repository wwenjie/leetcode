#include<iostream>
#include<vector>
#include<algorithm>

// 动态规划
// leetcode上提示执行超时

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals); 

int main() {
	//vector<vector<int>> intervals = {{0,2},{1,3},{2,4},{3,5},{4,6}};
	vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}}; //正确答案8
	int res = eraseOverlapIntervals(intervals);
	cout<<res<<endl;
	return 0;
}

/* 
状态转移方程：
	对所有 j<i && intervals[j][1] <= intervals[i][0]
	有 dp[i] = max(dp[i], dp[j] + 1)
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
		return a[0] < b[0];
	});
	
	int size = intervals.size();
	vector<int> dp(size, 1);

	for(int i=1; i<size; ++i) {
		for(int j=0; j<i; ++j) {
			if(intervals[j][1] <= intervals[i][0]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return size - *max_element(dp.begin(), dp.end());
}

