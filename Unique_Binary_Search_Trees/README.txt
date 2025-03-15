leetcode:
	96. 不同的二叉搜索树
	https://leetcode-cn.com/problems/unique-binary-search-trees/

参考：
	官方答案

思路：
	G(n): 长度为 n 的序列能构成的不同二叉搜索树的个数。
    F(i,n): 以i为根、序列长度为n的不同二叉搜索树个数 (1≤i≤n)

	G(n) = F(1,n) + F(2,n)...+ F(n,n)
    F(i,n) = G(i-1) * G(n-i)
    F(i,n) = F(n-i+1, n)

	for(int i=2; i<=n; i++)
		for(int j=1; j<=i; j++) {
			G[i] += G[j-1] * G[i-j];
		}
	
main1.cpp 递归
main2.cpp 数学推导，1个for循环
