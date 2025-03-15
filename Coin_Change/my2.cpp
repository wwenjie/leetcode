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
    vector<vector<int>> dp(n, vector<int>(amount+1, MAX_AMOUNT));
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=amount; j++){
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=amount; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i]){
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1);
            }
        }
    }
    int ans = dp[n-1][amount];

	// test begin ---->>>
	for(int i=0; i<n;i++) {
		for(int j=0; j<=amount; j++) {
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}

	// test end ------>>>


    return ans == MAX_AMOUNT ? -1 : ans;
}

int main() {
	vector<int> coins = {1,2,5}; // 预期结果 3
	int amount = 11;
	int ans = coinChange(coins, amount);
	cout<<ans<<endl;
	return 0;
}
