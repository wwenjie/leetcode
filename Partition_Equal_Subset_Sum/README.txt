leetcode：416题
	https://leetcode-cn.com/problems/partition-equal-subset-sum/

参考：
	https://blog.csdn.net/lw_power/article/details/103791719

思路：
	典型01背包问题

状态定义：
	dp[i][j]表示从数组[0,i]，是否存在子集，让子集和等于j。

状态转移方程：
	dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i]]

	3种情况：
		1. num[i] > j, dp[i][j] = dp[i-1][j]
		2. num[i]== j, dp[i][j] = true
		3. num[i] < j, dp[i][j] = dp[i-1][j] || dp[i-1][j-num[i]]
