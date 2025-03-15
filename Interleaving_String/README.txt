leetcode:
	97. 交错字符串
	https://leetcode-cn.com/problems/interleaving-string/

思路：
	(自己写出来的，代码跟官方答案几乎一样)
	动态规划
	TODO 滚动数组优化

	状态转移方程：
	dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || 
			   (dp[i][j-1] && s2[j-1] == s3[i+j-1])
	
	滚动数组：
	f[0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                f[j] &= (s1[i - 1] == s3[p]);
            }
            if (j > 0) {
                f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }
