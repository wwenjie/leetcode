519. 随机翻转矩阵
https://leetcode-cn.com/problems/random-flip-matrix/

思路：
	基本抄答案

	只初始化一个unordered_map保存已翻牌的下标x = i*n + j

	flip()关键点在于 
		从[0，total]随机x;
		随机完存map[x] = total;
		然后total--;
