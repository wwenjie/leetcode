/**
题目：
	给定一个数组 prices ，它的第??i 个元素??prices[i] 表示一支给定股票第 i 天的价格。
	你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
	返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例：
	输入：[7,1,5,3,6,4]
	输出：5
	解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
**/

/**
https://www.cnblogs.com/grandyang/p/4280131.html
此博客还说到另外2个股票问题
**/


#include<iostream>
#include<vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {
	int res = 0;
	int buy = INT_MAX;
	for (int price : prices) {
		buy = min(buy, price);
		res = max(res, price-buy);
	}
	return res;
}

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	int res = maxProfit(prices);
	cout<<"res: "<<res<<endl;
	return 0;
}
