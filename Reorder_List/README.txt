143.重排链表
https://leetcode-cn.com/problems/reorder-list/

思路：
	法1：
		全扔到vector里，vector可以根据下标取node，再按规则重排，
		时间空间复杂度都O(n)。
	法2：
		a. 快慢指针法来找到原链表的中点,O(n)
		b. 迭代法使右半链表反转
		c. 2链表合并
