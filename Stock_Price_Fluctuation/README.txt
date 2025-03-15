2034. 股票价格波动
https://leetcode-cn.com/problems/stock-price-fluctuation/

medium

map
multimap

const_iterator：不能改它指向的值
const iterator：初始化后不能指向其他下标

multimap的遍历
	lower_bound
	update_bound
	multimap没下标运算


如果需要按照达到小排序，则
	multimap<int,int,greater<int>>
	map<int,int,greater<int>>
	默认是less<int>


遗留问题：
	wsl上本地跑没问题，输出也跟答案一样
	在lc上跑，好像溢出了，heap-use-after-free on 0x....
