220. 存在重复元素 III
https://leetcode-cn.com/problems/contains-duplicate-iii/

滑动窗口 + 窗口内桶排序
因为每个桶只能一个元素，所以hash表一个键值对表示一个桶

	时间O(n)
	空间O(min(n,k))



本地最特别注意点在于int边界问题，如INT_MAX+1

	int 4位
	long 32位系统4位，64位系统8位
	long long 64位

	int: -2147483648 ~ 2147483647

	abs(-1 - INT_MAX) 因为int没法取到 2147483648，所以依然== -2147483648


