leetcode: 
	31. Next Permutation
	https://leetcode-cn.com/problems/next-permutation/

题目：
	实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
	如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
	必须原地修改，只允许使用额外常数空间。

示例：
	Input: nums = [1,2,3]
	Output: [1,3,2]

参考：
	https://zhuanlan.zhihu.com/p/45007701

思路：
	主要是找到规律，从后开始，先找到nums[i] > nums[i+1]的数，再找i后面比nums[i]大的最小的数，交换，再把下标i后面的数字reverse，以保证后面的数从小到大。
