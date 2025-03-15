324. 摆动排序 II
https://leetcode-cn.com/problems/wiggle-sort-ii/

思路：
	联系QuickSelect目录 快速选择算法

笔记：
	vector<int> tmp1(nums.begin(), mid_iter);
	vector<int>::iterator mid_iter 指向的是下标4，tmp1拷贝的是0~3项
