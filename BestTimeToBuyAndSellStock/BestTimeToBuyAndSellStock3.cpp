/*
题目：
	给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
	设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
示例：
	输入：prices = [3,3,5,0,0,3,1,4]
	输出：6
	解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
	随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。


这个好难，参考
https://www.cnblogs.com/grandyang/p/4281975.html
	有4道题的详解
https://blog.csdn.net/linhuanmars/article/details/23236995
	解答了local[i][j]后半部分的原因，醍醐灌顶！
	第二个量则是取local第i-1天j次交易，然后加上今天的差值（这里因为local[i-1][j]比如包含第i-1天卖出的交易，所以现在变成第i天卖出，并不会增加交易次数，而且这里无论diff是不是大于0都一定要加上，因为否则就不满足local[i][j]必须在最后一天卖出的条件了）。
*/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
[局部最优和全局最优解法]
    1.到第i天最多进行j次交易，最好的利润为global[i][j]
    2.到第i天最多进行j次交易，且最后一次交易在当天卖出，最好的利润为local[i][j]

递推式：
    局部最优解 local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff)
    全局最优解 global[i][j] = max(local[i][j], global[i-1][j])
*/
int maxProfit(vector<int>& prices) {
	if (prices.empty()) {
	    return 0;
	}
	int size = prices.size();
	//在leetcode报错 variable-sized object may not be initialized
	int global[size][3] = {0};
	int local[size][3] = {0};
	//int global[size][3];
	//int local[size][3];
	//memset(global, 0, sizeof(global));
	//memset(local, 0, sizeof(local));
	
	for (int i=1; i<size; ++i) {
	    int diff = prices[i] - prices[i-1];
	    for (int j=1; j<=2; ++j) {
	        local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
	        global[i][j] = max(local[i][j], global[i-1][j]);
	    }
	}
	return global[size-1][2];
}

int main() {
	vector<int> prices = {3,3,5,0,0,3,1,4};
	int res = maxProfit(prices);
	cout<<"res --->> "<<res<<endl;
	return 0;
}


/* 试下编译器不知道数组长度，用变量声明数组会怎么样
void fun(int num) {
	int a[num] = {0};
	for(int i=0; i<num; i++)
		cout<<a[i]<<endl;

}

int main() {
	int num = 10;
	cin>>num;
	fun(num);
	return 0;
}
*/
