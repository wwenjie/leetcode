#include<iostream>

using namespace std;

#define MAX 20

int normal_array();
int scrolling_array();

int main() {
	int sum;
	
	sum = normal_array();
	cout<<"normal_array: "<<sum<<endl;
	sum = scrolling_array();
	cout<<"scrolling_array: "<<sum<<endl;


	return 0;
}

// 普通二位数组
int normal_array(){
	int d[MAX][MAX];
	for (int i=0; i<MAX; i++)
		d[i][0] = 1;
	for (int j=0; j<MAX; j++)
		d[0][j] = 1;
	cout<<d[0][1]<<endl;
	for (int i=1; i<MAX; i++) {
		for(int j=1; j<MAX; j++) {
			d[i][j] = d[i-1][j] + d[i][j-1];
		}
	}
	return d[MAX-1][MAX-1];
}

// 二位数组 用 滚动数组
// 因为dp[i][j]跟2个维度都有关，所以没法对空间优化成一位数组
int scrolling_array(){
	long d[2][MAX];
	for (int i=0; i<2; i++)
		d[i][0] = 1;
	for (int j=0; j<MAX; j++)
		d[0][j] = 1;
	for (int i=1; i<MAX; i++) {
		for (int j=1; j<MAX; j++) {
			d[i%2][j] = d[(i-1)%2][j] + d[i%2][j-1];
		}
	}
	return d[((MAX-1)%2)][MAX-1];
}

