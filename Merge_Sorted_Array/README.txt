leetcode:	88. Merge Sorted Array
https://leetcode-cn.com/problems/merge-sorted-array/

题目示例：
	输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
	输出：[1,2,2,3,5,6]

思路：
	从末尾比较大小，直接插入nums1的末尾。
	重点是不要从前面比较
