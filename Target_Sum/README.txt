494. 目标和
https://leetcode-cn.com/problems/target-sum/

方法：
iteration.cpp 
	我写的迭代法
	1916ms
backtracing.cpp
	回溯
	我做的和标准答案差不多
	时间O(2^n),1068ms，超28.3%
dp.cpp
	我写的dp，和标准答案dp
	我的写的边界条件有bug，详见注释
	时间O(n * neg)

	边界条件：
        sum = nums的总和
        取出可以为负的情况
        若'-'的总和为neg，则'+'的总和为sum-neg
        则(sum-neg)-neg = target
        即neg = (sum - target) /2
        所以从nums中取出部分的数，使总和为neg即可
        相当于01背包问题
    状态转移方程：
        前i个数的和等于j的方案数
        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
        return dp[n-1][neg];
