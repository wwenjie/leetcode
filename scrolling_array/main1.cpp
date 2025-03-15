#include<iostream>

using namespace std;

#define MAX 20

int fib_normal();
int fib_scrolling_array1();
int fib_scrolling_array2();

int main() {
	int sum;
	
	sum = fib_normal();
	cout<<"fib_normal: "<<sum<<endl;
	sum = fib_scrolling_array1();
	cout<<"fib_scrolling_array1: "<<sum<<endl;
	sum = fib_scrolling_array2();
	cout<<"fib_scrolling_array1: "<<sum<<endl;


	return 0;
}

int fib_normal() {
	long d[MAX];
	d[0] = 1;
	d[1] = 1;
	for(int i = 2; i<MAX; i++) {
		d[i] = d[i-1] + d[i-2];
	}
	return d[MAX-1];
}

// 滚动数组
int fib_scrolling_array1(){
	long d[3];
	d[1] = 1;
	d[2] = 1;
	for (int i=2; i<MAX; i++) {
		d[0] = d[1];
		d[1] = d[2];
		d[2] = d[0] + d[1];

		// 或者改成d[2],然后加一个temp
		// temp = d[0];
		// d[0] = d[1];
		// d[1] = temp + d[0]
	}
	return d[2];
}

// for内改成只有一个表达式
int fib_scrolling_array2(){
	long d[3];
	d[0] = 1;
	d[1] = 1;
	for (int i=2; i<MAX; i++) {
		d[i%3] = d[(i-1)%3] + d[(i-2)%3];
	}
	return d[(MAX-1) % 3];
}
