
// 根据等差数列求和公式，前k项和 sum = k * (k+1) / 2
// 可通过二分法查找n

int arrangeCoins(int n) {
	int left = 1, right = n;
	while(left < right) {
		int mid = (right - left + 1) / 2 + left;
		// 这里(long long) 是重点
		if ( (long long) mid * (mid+1) <= (long long) 2 * n)
			left = mid;
		else 
			right = mid - 1;
	} 
	return left;
}
