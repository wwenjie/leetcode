#include <iostream>
#include <vector>
#include <stdio.h>
#include <functional>
using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int ans = gcd(20,6);
	cout << ans << endl;
	ans = gcd(20,5);
	cout << ans << endl;
	ans = gcd(75,36);
	cout << ans << endl;
	ans = gcd(75,25);
	cout << ans << endl;
	ans = gcd(20,16);
	cout << ans << endl;
	ans = gcd(0,5);
	cout << ans << endl;
	ans = gcd(5,0);
	cout << ans << "," << (0 % 5) << endl;

	return 0;
}
