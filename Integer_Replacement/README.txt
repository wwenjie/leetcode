397. 整数替换
https://leetcode-cn.com/problems/integer-replacement/

错解：
	n = (n % 2 == 0) ? (n/2) : (n-1);
	这是不可以的
	因为 (n+1) % 4 == 0 的情况更优
	n == 3时也特殊

normal.cpp
	找规律

bit_operation.cpp
	位运算

dp.cpp
	会超时
	n=200000000时，要6秒，bit_operation.cpp耗时0秒。
