#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

/*
边界条件：
    sum = nums的总和
    取出可以为负的情况
    若'-'的总和为neg，则'+'的总和为sum-neg
    则(sum-neg)-neg = target
    即neg = (sum - target) /2
    所以从nums中取出部分的数，使总和为neg即可
    相当于01背包问题
状态转移方程：
    前i个数的和等于j的方案数
    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
    return dp[n-1][neg];
*/

// 错误答案，边界取的有问题，提交总是有部分输入用例不对
// 原因是见下面注释
int findTargetSumWays2(vector<int>& nums, int target) {
    int sum = 0;
    for(int& num: nums)
        sum += num;
    int diff = sum - target;
    if (diff % 2 != 0 || diff < 0)
        return 0;
    int neg = diff / 2;
    int n = nums.size();        
    vector<vector<int>> dp(n, vector<int>(neg+1, 0));
    for(int j=1; j<=neg; j++)
        dp[0][j] = (nums[0] == j ? 1 : 0); // 这里有bug！！！当nums[0]=j=0时，dp[0][0]=2
    for(int i=0; i<n; i++)
        dp[i][0] = 1; // 这里也有bug！！！当nums前i个数存在0的情况，j==0的选择不知1种，因为nums中0的项可以取也可以不取
    for(int i=1; i<n; i++){
        int num = nums[i];
        for(int j=1; j<=neg; j++){
            if(j >= num){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-num];
				printf("dp[%d][%d] = %d + %d\n" , i,j, dp[i-1][j],dp[i-1][j-num]);
            }
            else{
                dp[i][j] = dp[i-1][j]; 
				printf("dp[%d][%d] = %d\n" , i,j, dp[i-1][j]);
            }
        }
    }
	// test 1------>>>
	for(int i=0; i<n; i++) {
		for(int j=0; j<=neg; j++){
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}

	// test 2------>>>

    return dp[n-1][neg];
}

// 正确答案，在于边界条件
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int& num: nums)
        sum += num;
    int diff = sum - target;
    if (diff % 2 != 0 || diff < 0)
        return 0;
    int neg = diff / 2;
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(neg+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        int num = nums[i-1];
        for(int j=0; j<=neg; j++){
            if(j >= num){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-num];
				printf("dp[%d][%d] = %d + %d\n" , i,j, dp[i-1][j],dp[i-1][j-num]);
            }
            else{
                dp[i][j] = dp[i-1][j];
				printf("dp[%d][%d] = %d\n" , i,j, dp[i-1][j]);
            }
        }
    }
	// test 1------>>>
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=neg; j++){
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
	// test 2------>>>

    return dp[n][neg];
}

int main() {
	//vector<int> nums = {1,1,1,1,1};
	// int target = 3;
	vector<int> nums = {1,0};
	int target = 1;
	int ans;
	ans = findTargetSumWays(nums, target);
	cout<<ans<<endl;

	cout<<"-----"<<endl;
	ans = findTargetSumWays2(nums, target);
	cout<<ans<<endl;

	return 0;
}
