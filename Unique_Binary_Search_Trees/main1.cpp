#include<iostream>
#include<vector>

using namespace std;

int numTrees(int n);
int cal(vector<vector<int>>& dp, int n);
int cal(vector<vector<int>>& dp, int head, int n);

int main() {
	int n = 3;
	int res = numTrees(n);
	cout<<res<<endl;
	return 0;
}

int numTrees(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    return cal(dp, n);
}

int cal(vector<vector<int>>& dp, int n) {
    if (n == 0) {
        return 1;
    }
    else if( n == 1) {
        return 1;
    }
    else if(n == 2) {
        return 2;
    }
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += cal(dp, i, n);
    }
    return sum;
}
int cal(vector<vector<int>>& dp, int head, int n) {
    if (dp[head][n])
        return dp[head][n];

    int left = cal(dp, head - 1);
    int right = cal(dp, n - head);
    int sum = left * right;
    dp[head][n] = sum;
    dp[n-head+1][n] = sum;
    return sum;
}
