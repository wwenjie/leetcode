leetcode:
	剑指 Offer 33. 二叉搜索树的后序遍历序列
	https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

参考：
	https://blog.csdn.net/qq_32523711/article/details/108338949

思路：
	递归fun():
		找到右子树，
		判断右子树节点是否都小于根节点，
	
		是则继续递归对左子树的序列，和右子树的序列执行fun().

思路2：
	博客说很巧妙，懒得看了
