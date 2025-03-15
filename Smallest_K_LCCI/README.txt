面试题 17.14. 最小K个数
https://leetcode-cn.com/problems/smallest-k-lcci/

思路：
	1.普通排序
		2行代码完事
	2.大顶堆
		priority_queue，先插入k个，遍历剩下的，小于top()，就pop()顶部掉再push()新的。
	3.快排
		递归partition前k个
		用到srand(),time(),rand()
		
