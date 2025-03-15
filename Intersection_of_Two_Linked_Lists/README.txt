leetcode：160相交链表
	https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

参考：
	https://blog.csdn.net/zhizhengguan/article/details/106190997

思路：
	法1：set，空间复杂度O(n)，时间复杂度O(n)
	法2：得到2个链表长度，分别m、n，且m>n，则长链表从m-n处开始遍历，短链表从头开始便利，时间复杂度O(n)，空间复杂度O(1)
