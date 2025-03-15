#include <iostream>
#include <vector>
#include <stdio.h>
#include <functional>
using namespace std;

// 法1 回溯法，自写
// 181ms，耗时击败8%，内存击败44%
// 时间复杂度o(n!)，空间复杂度O(n)，dfs的栈深度为n
int countArrangement1(int n)
{
	vector<bool> mark(n + 1, false);

	std::function<int(int)> dfs = [&](int idx)
	{
		if (idx > n)
		{
			return 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (mark[i])
				continue;
			if (i % idx != 0 && idx % i != 0)
				continue;
			mark[i] = true;
			ans += dfs(idx + 1);
			mark[i] = false;
		}
		return ans;
	};
	return dfs(1);
}

// 法2 状态压缩 + 回溯，自写
// 104ms，耗时击败19%，内存击败43%
// 时间复杂度O(n!)，空间复杂度O(n)
int countArrangement2(int n)
{
	int mark = 0;
	std::function<int(int)> dfs = [&](int idx)
	{
		if (idx > n)
		{
			return 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (mark & (1 << i))
				continue;
			if (i % idx != 0 && idx % i != 0)
				continue;
			mark |= (1 << i);
			ans += dfs(idx + 1);
			mark ^= (1 << i);
		}
		return ans;
	};
	return dfs(1);
}

// 法3 状态压缩 + 回溯 + 记忆化搜索
// 5ms，cpu击败79%，内存击败11%
// 时间复杂度O(n!)，空间复杂度O(n)
// TODO，没想明白为啥记忆化没用二维数据组memo[i][mark]为啥没问题
int countArrangement3(int n)
{
	int mark = 0;
	vector<int> memo(1 << (n + 1), -1); // 表示mark状态下，有多少种排列
	std::function<int(int)> dfs = [&](int idx)
	{
		if (memo[mark] != -1)
			return memo[mark];
		if (idx > n)
			return 1;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (mark & (1 << i))
				continue;
			if (i % idx != 0 && idx % i != 0)
				continue;
			mark |= (1 << i);
			ans += dfs(idx + 1);
			mark ^= (1 << i);
		}
		memo[mark] = ans;
		return ans;
	};
	return dfs(1);
}

/*
 * 法4 状态压缩 + 动态规划
 * 定义：dp[mark]表示状态位mark时，有多少种排列
 * 状态转移方程：dp[mark] = dp[mark &= ~(1 << i)
 * 耗时8ms，耗时击败67%，内存击败63%
 * 时间复杂度O(2^n * n)，空间复杂度O(n)
 */
int countArrangement4(int n)
{
	vector<int> dp(1 << n, 0);
	// 初始状态
	for (int i = 0; i < n; ++i)
	{
		// 每个数都能放第1位
		dp[1 << i] = 1;
	}
	for (int mark = 1; mark < (1 << n); ++mark)
	{
		int cnt = __builtin_popcount(mark);
		if (cnt == 1)
			continue;
		for (int j = 1; j <= n; ++j)
		{
			if ((mark & (1 << (j - 1))) == 0)
				continue;
			if (cnt % j != 0 && j % cnt != 0)
				continue;
			// 满足条件
			dp[mark] += dp[mark & (~(1 << (j - 1)))];
		}
	}
	return dp[(1 << n) - 1];
}

/*
 * 法5 状态压缩 + 动态规划
 * 方法同法4，只是改下for逻辑
 * 耗时、内存同上
 */
int countArrangement(int n)
{
	vector<int> dp(1 << n, 0);
	// 初始状态
	for (int i = 0; i < n; ++i)
	{
		// 每个数都能放第1位
		dp[1 << i] = 1;
	}
	for (int mark = 1; mark < (1 << n); ++mark)
	{
		int cnt = __builtin_popcount(mark);
		for (int j = 1; j <= n; ++j)
		{
			if ((mark & (1 << (j - 1))) > 0)
			{
				// 遍历到为1的位，不处理
				continue;
			}
			if ((cnt + 1) % j != 0 && j % (cnt + 1) != 0)
			{
				// 不满足条件
				continue;
			}
			// 满足条件
			dp[mark | (1 << (j - 1))] += dp[mark];
		}
	}
	return dp[(1 << n) - 1];
}

int main()
{
	int ans = countArrangement(2);
	cout << ans << endl;

	return 0;
}
