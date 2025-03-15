#include<iostream>
#include <climits>
#include<ctime>

// 位运算 后2位只有4种情况： 00 01 10 11

using namespace std;

int integerReplacement(int n);

int main() {
	int nums[] = {7, 2147483647, 3, 65535, 200000000};
	// 答案：4,32,2,17
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
    int cnt = 0;
    while(n > 1){
		if((n & 1) == 0) //偶数
			n >>= 1;
		else if ((n & 2) == 0 || n == 3) // 奇数
			n--;
		else if((n & 3) == 3)
			n++;
		else
			cout<<"err----->>"<<endl;
        cnt++;
    }
    return cnt;
}
