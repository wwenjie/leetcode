#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

#define NUM 4
#define CAPACITY 8

int FindMax1(int w[], int v[]); 
int FindMax2(int w[], int v[]); 

int main() {
	int w[NUM+1] = {0,2,3,4,5};
	int v[NUM+1] = {0,3,4,5,6};
	int max1 = FindMax1(w, v);
	int max2 = FindMax2(w, v);
	cout<<"max1: "<<max1<<endl;
	cout<<"max2: "<<max2<<endl;
	return 0;
}

// 状态方程：
// 1. w(i) > j, V(i,j) = V(i-1, j)
// 2. w(i)<= j, V(i,j) = max{V(i-1, j), V(i-1, j-w(i)) + v(i)}
int FindMax1(int w[], int v[]) {
	int dp[NUM+1][CAPACITY+1] = {0};
	for (int i=1; i<=NUM; i++){
		for (int j=1; j<=CAPACITY; j++){
			if(w[i] > j){ // 装不下
				dp[i][j] = dp[i-1][j];
			}
			else { // 能装
				if(dp[i-1][j] > dp[i-1][j-w[i]] + v[i]) {
					dp[i][j] = dp[i-1][j];
				}
				else {
					dp[i][j] = dp[i-1][j-w[i]] + v[i];
				}
			}
		}
	}
	// cout<<"111--->>"<<endl;
	// for (int i=0; i<=NUM; i++){
	// 	for (int j=0; j<=CAPACITY; j++){
	// 		cout<<dp[i][j]<<endl;
	// 	}
	// }
	// cout<<"222--->>"<<endl;
	return dp[NUM][CAPACITY];
}

// 空间优化，滚动数组，改为一维
// 状态方程：
// 1. w(i) > j, V(j) = V(j)
// 2. w(i)<= j, max{V(j) , V(j) = V(j-w(i)) + v(i)
int FindMax2(int w[], int v[]) {
	int dp[CAPACITY+1] = {0};
	for (int i=1; i<=NUM; i++){
		for (int j=CAPACITY; j>=0; j--){
			// if(w[i] > j){ // 装不下
			// 	dp[j] = dp[j];
			// } 
			// else { // 装得下

			if (dp[j] <= dp[j - w[i]] +v[i] && j >= w[i]){ 					
				dp[j] = dp[j - w[i]] + v[i];
			}
		}
	}
	return dp[CAPACITY];
}
