322. 零钱兑换
https://leetcode-cn.com/problems/coin-change/

dp, 完全背包问题


这个题解不错:https://leetcode-cn.com/problems/coin-change/solution/wan-quan-bei-bao-wen-ti-de-san-bu-you-hu-7oh8/

my.cpp
	我的原始做法，和上面题解一样
my2.cpp
	模仿上面题解的优化1，初始dp[][] = {-1}，改成dp[][] = {10001}，逻辑好看了很多
my3.cpp
	模仿上述题解的优化2，滚动数组优化。和标准答案一样。
	这个关于滚动数组优化的的博客坑死我了
		https://www.it610.com/article/1297540274498641920.htm
	它说	
		for(i: 1 ~ n-1)
			for(j: 1 ~ amount )
				dp[i][j] = ...
	要改成
		for(i: 1 ~ n-1)
			for(j: amount ~ 1)
				dp[j] = ...
	其中j要逆序，根本不用，因为dp[j] 要依赖同一行前面dp[j-coins[i]]的计算，至于这个博客为什么这么说，还不理解
