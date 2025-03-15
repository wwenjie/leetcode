/**
122. 买卖股票的最佳时机 II

相对于第一道题，可以多次买入卖出

贪心算法
	因为[1,3,5,6] 的利润为 2+2+1 == 6-1
**/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int res = 0;
	int size = prices.size();
	for (int i=0; i<size-1; i++) {
		if (prices[i] < prices[i+1]){
			res += prices[i+1] - prices[i];
		}
	}
	return res;
}

int main() {
	vector<int> prices = {7,1,5,3,6,4};
	int res = maxProfit(prices);
	cout << res <<endl;
	return 0;
}
