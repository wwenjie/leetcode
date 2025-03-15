372. 超级次方
https://leetcode-cn.com/problems/super-pow/

medium

忘记这些数学规律了，基本抄的。

快速幂算法+迭代
数学
	取模满足分配律
	    (a * b) % m = [(a % m) * (b % m)] % m
	指数计算也满足
	    (a^b)^10 = a^(b*10)
