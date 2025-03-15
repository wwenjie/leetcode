#include<iostream>
#include<vector>

using namespace std;

/*
前i种硬币，组成总额j的最少硬币数为：
dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1)
*/
const int MAX_AMOUNT = 10001;
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, MAX_AMOUNT);
    for(int j=0; j<=amount; j++){
        if (j % coins[0] == 0)
            dp[j] = j / coins[0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=amount; j++){
            if(j >= coins[i])
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);
        }
		// test 0--->>
		for(int j=0;j<=amount;j++)
			cout<<dp[j]<<"  ";
		cout<<endl;
		// test 1--->>
    }
    return dp[amount] == MAX_AMOUNT ? -1 : dp[amount];
}


int main() {
	vector<int> coins = {1,2,5}; // 预期结果 3
	int amount = 11;
	int ans = coinChange(coins, amount);
	cout<<ans<<endl;
	return 0;
}
