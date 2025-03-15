#include<iostream>
#include<vector>

using namespace std;

//原题英文说的是choose选择，而不是随机抽
//实际做法也是跟随机抽的一样，遍历任何情况，必须不存在

bool canIWin(int maxChoosableInteger, int desiredTotal);
bool canIWin(int maxChoosableInteger, int desiredTotal, vector<int>& dp, int state,  bool turn);

int main() {
	int maxChoosableInteger = 10;
	int desiredTotal = 40;
	bool ans = canIWin(maxChoosableInteger, desiredTotal);
	cout<<ans<<endl;
	return 0;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
	if(maxChoosableInteger >= desiredTotal){
		return true;
	}
	if(maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal){
		// 1~n之和 < desiredTotal
		// 等差数列求和公式
		return false;
	}
	// dp[state]表示state状态下，先手能否赢得比赛，2表示未计算，1表示能，0表示不能
	// state取值在0~2^(n+1)-1，二进制位第i位表示第i张牌是否被选。
	vector<int> dp(1<<maxChoosableInteger, 2);
    return canIWin(maxChoosableInteger, desiredTotal, dp, 0, true);
}

bool canIWin(int maxChoosableInteger, int desiredTotal, vector<int>& dp, int state, bool turn) {
	// turn：true我方，false对方
	if (dp[state] != 2)
		// 没有这个dp，算法会从秒解变成十几秒超时
		return dp[state];
	for(int i=1; i<=maxChoosableInteger; i++){
	    if (state & (1<<(i-1)))
	        // 第i张牌被选
	        continue;
	    if (desiredTotal - i <= 0){
			// 我赢了
			dp[state] = true;
			return true;
		}
	    bool ans = canIWin(maxChoosableInteger, desiredTotal-i, dp, state | (1<<(i-1)), !turn);
		if (ans == false){
			// 对手输了
			dp[state] = true;
			return true;
		}

	}
	dp[state] = false;
	return false;
}
