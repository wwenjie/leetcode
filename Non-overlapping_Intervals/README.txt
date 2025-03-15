leetcode:
	435. 无重叠区间
	https://leetcode-cn.com/problems/non-overlapping-intervals/

# 思路

	main1.cpp 
		我最初写的典型错误方法，用的Merge_Interval题的那种排序方法，明显是不行的
		反例：[1,10],[2,3],[3,4]
	main2.cpp 
		贪心，按照最小右端点来排序，不断加入右端点最小的区间。
	main3.cpp 
		动态规划，看答案的，理解还不够深刻
		官方答案有，但leetcode提示执行超时
