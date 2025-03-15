198. 打家劫舍
https://leetcode-cn.com/problems/house-robber/

思路：
	动态规划
	dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

	滚动数组
