BestTimeToBuyAndSellStock.cpp
	简单，遍历一遍即可

BestTimeToBuyAndSellStock2.cpp
	简单，贪心算法

BestTimeToBuyAndSellStock3.cpp
	难
	问：local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
		后半部为啥不是local[i-1][j-1] + diff)
	答：local[i-1][j]包含i-1天的交易，若改成第i天交易，并不会改变交易次数，但需要加diff。

	问：还有也未解决为啥linux可以变量初始化数组长度?而leetcode和win上不可以
	答：？
BestTimeToBuyAndSellStock4.cpp
	leetcode上做了，跟第三题几乎一样，没抄下来了

参考：https://www.cnblogs.com/grandyang/p/4281975.html
