#include <iostream>
#include <vector>
#include <stdio.h>
#include <functional>
using namespace std;

static const int mod = 1e9 + 7;
int specialPerm(vector<int> &nums)
{
	int n = nums.size();
	// 当前状态有2^n(即1<<n)种情况
	// ve[x][y] 表示当前x状态，且最后一个元素的下标为y时，剩余元素满足special要求的排列数
	vector<vector<int>> ve(1 << n, vector<int>(n, -1));

	std::function<int(int, int)> dfs = [&](int state, int i)
	{
		// if (ve[state][i] != -1) {
		// 	// 当前state状态，且下一个数是第i个数的情况，已经遍历过，不重新计算，返回当前的值
		// 	cout << "1----->>>" << state << ", " << i << ", " << ve[state][i] << endl;
		//      return 0;
		// }
		if (state == ((1 << n) - 1))
		{
			return 1;
		}
		if (ve[state][i] != -1)
		{
			return ve[state][i];
		}

		int ans = 0;
		// 遍历每个数字，没在state里就作为下一位
		for (int j = 0; j < n; ++j)
		{
			if ((state >> (n - j - 1)) & 1)
			{
				// state的第j位，已经在排列里，不处理
				continue;
			}
			if (nums[i] % nums[j] != 0 && nums[j] % nums[i] != 0)
			{
				// 最后一个数是nums[i]，下一个数据是nums[j] 的情况不满足条件
				continue;
			}

			// 到这里已经满足条件
			int new_state = state | (1 << (n - j - 1));

			// ve[new_state][j] = 1;
			ans += dfs(new_state, j);
		}
		ve[state][i] = ans;
		return ans;
	};

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		res += dfs(1 << i, n - 1 - i);
	}
	return res;
}

int main()
{
	// vector<int> nums = {1,1,1,1,1};
	//  int target = 3;
	// vector<int> nums = {1,4,3};
	// vector<int> nums = {2,3,6};
	// vector<int> nums = {20,100,50,5,10,70,7};
	// vector<int> nums = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
	vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

	int ans = specialPerm(nums);
	cout << ans << endl;

	return 0;
}
