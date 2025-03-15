#include <stdio.h>
#include <iostream>
#include <vector>

// 计算斐波那契数列
// 递归占用内存大，可能栈溢出而程序崩溃
// 于是考虑用数组保存曾经计算过的数据来避免重复计算，这种思想就是动态规划

using namespace std;

int fib1(int n, vector<int>& ve);
int fib2(int n );

int main() {
	
	int num = 20;

	// 1 递归
	vector<int> ve(num+1, -1);
	int res1 = fib1(num, ve);
	cout<<res1<<endl;

	// 2 动态规划
	int res2 = fib2(num);
	cout<<res2<<endl;
	return 0;
}


// 递归，保存vector引用避免重复计算
int fib1(int n, vector<int>& ve) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	if (ve[n] == -1){
		ve[n] = fib1(n-1, ve) + fib1(n-2, ve);
	}
	return ve[n];
}


// 动态规划
// 递归问题转化为循环来解决
int fib2(int n){
	if (n == 0)
		return 0;
	if (n == 1){
		return 1;
	}
	int n0 = 0;
	int n1 = 1;
	int temp;

	for(int i=1; i<n; ++i){
		temp = n1;
		n1 = n0 + n1;
		n0 = temp;
	}

	return n1;
}
