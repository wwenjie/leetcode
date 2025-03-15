leetcode: 1337 矩阵中战斗力最弱的 K 行
https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/


思路：
	先算每行的值
	再用冒泡排序或选择排序，遍历k次即可，取前k次的值

其他：
	用到pair，pair<int,int>，数据对
	accumulate，计算vector中所有数据的和
	swap，交换vector不同下标数据的位置
	sort，对vector(pair<int, int>)
