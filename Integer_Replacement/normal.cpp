#include<iostream>

// TODO 错了，关键在于 n+1 % 4 == 0 的情况

using namespace std;

int integerReplacement(int n);

int main() {
	int ans = integerReplacement(65535);
	cout<<ans<<endl;
	return 0;
}

int integerReplacement(int n) {
	if (n == INT_MAX)
        return 32;
    int cnt = 0;
    while(n > 1){
        //n = (n % 2 == 0) ? (n/2) : (n-1);
        if ((n+1) % 4 == 0 && n != 3)
            n = n + 1;
        else if (n % 2 == 0)
            n /= 2;
        else 
            n--;
        cnt++;
    }
    return cnt;
}
