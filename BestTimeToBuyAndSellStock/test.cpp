
前i天可以完成j次交易的最大利润
local[i][j] = max(local[i-1][j], local[i-1][j-1] + nums[i]-nums[i-1])

前i天的最大利润
global[i] = max(global[i-1], global[i])

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int ans = 0;

	return ans;
}
