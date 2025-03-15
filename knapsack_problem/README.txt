背包问题.




参考：
https://www.cnblogs.com/Christal-R/p/Dynamic_programming.html
01背包问题，讲的很细

https://zhuanlan.zhihu.com/p/93857890
01背包问题，完全背包问题，多重背包问题


完全背包问题

分析一：
	1. w[i] > j, dp[i][j] = dp[i-1][j]
	2. w[i]<= j, dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + v[i])
		2.1 不装入第i件物品，则dp[i-1][j];
		2.2 装入1件第i件物品，则dp[i-1][j-w[i]] + v[i]
		2.3 装入多见第i间物品，则dp[i][j-w[i]] + v[i]
		因为2.2的式子<=2.3的式子，所以得出上述结论。

分析二：
	转换成01背包问题


恰好装满的01背包问题
https://blog.csdn.net/lw_power/article/details/103791719
leetcode 分割等和子集
