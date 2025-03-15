213. 打家劫舍 II
https://leetcode-cn.com/problems/house-robber-ii/

思路：
	同打家劫舍I，dp

	计算max(rob(nums, 0, n-2), rob(nums, 1, n-1)) 即可

	注意滚动数组优化
