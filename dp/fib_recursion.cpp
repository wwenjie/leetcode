#include <stdio.h>
#include <iostream>

// 计算斐波那契数列
// 递归，递归次数太多可能栈溢出

using namespace std;

int fib(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	return fib(num-1) + fib(num-2);
}

int main() {
	
	int max = 20;
	int res = fib(20);
	cout<<res<<endl;
	return 0;
}
