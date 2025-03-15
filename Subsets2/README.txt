leetcode:
	90. Subsets II
	https://leetcode-cn.com/problems/subsets-ii/

参考：
	https://www.cnblogs.com/ariel-dreamland/p/9159492.html

思路：
main.cpp
	拿题目中的例子[1 2 2]来分析，根据之前 Subsets 子集合 里的分析可知，当处理到第一个2时，此时的子集合为[], [1], [2], [1, 2]，而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，所以只能在上一个循环生成的后两个子集合后面加2

main2.cpp
	还没理解，比原题，多了一行
	while (S[i] == S[i + 1]) ++i;
