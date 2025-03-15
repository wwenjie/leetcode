#include<iostream>
#include<climits>
#include<vector>
#include<ctime>

// 位运算 后2位只有4种情况： 00 01 10 11

using namespace std;

int integerReplacement(int n);

int main() {
	int nums[] = {8, 7, 2147483647, 3, 65535, 200000000};
	//int nums[] = {200000000};
	// 答案：3,4,32,2,17
	for(int num: nums){
		clock_t start_time = clock();
		int ans = integerReplacement(num);
		clock_t end_time = clock();
		cout<<"time: "<<(double)(end_time-start_time)/CLOCKS_PER_SEC<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

int integerReplacement(int n) {
	if (n == INT_MAX)
        return 32;
    vector<int> dp(n+2, 0);
    dp[1] = 0;
    dp[2] = 1;
	// 法1
	for(int i=3; i<=n; i++) {
		//if (i & 1) {
		if (i % 2) {
			//奇数
			dp[i] = min(dp[(i+1)/2] + 2, dp[i-1] + 1);
		}
		else {
			//偶数
			dp[i] = dp[i/2] + 1;
		}
	}

	// 法2
    //for(int i=3; i<=n; i+=2){
	//	dp[i+1] = dp[(i+1)/2] + 1;
    //    dp[i] = min(dp[i-1], dp[i+1]) + 1;
	//	//cout<<"dp["<<(i+1)<<"]"<<" = "<<dp[i+1]<<endl;
	//	//cout<<"dp["<< i   <<"]"<<" = "<<dp[i]  <<endl;
    //}
    return dp[n];
}
