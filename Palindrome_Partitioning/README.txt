leetcode: 131. 分割回文串
	https://leetcode-cn.com/problems/palindrome-partitioning/

题目：
	给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
	回文串 是正着读和反着读都一样的字符串。

示例：
	输入：s = "aab"
	输出：[["a","a","b"],["aa","b"]]

参考：
	https://www.cnblogs.com/wmx24/p/9882297.html
	https://blog.csdn.net/weixin_42156844/article/details/102682085

思路：
	先算出所有回文串，再用回溯法，得出不同的组合


main1.cpp 时间复杂度O(n^2)，遍历得出所有回文串，再dfs回溯法

main2.cpp 先动态规划，得出所有回文串，再dfs回溯法
	参考 https://leetcode-cn.com/problems/palindrome-partitioning/solution/fen-ge-hui-wen-chuan-by-leetcode-solutio-6jkv/
	时间空间复杂度详见上述网址。
