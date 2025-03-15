#include <iostream>
#include <vector>
#include <stdio.h>
#include <functional>
using namespace std;

    /*
    法1：
    经典的数学问题，2个壶能量出的水量一定是2个壶容量的最大公约数的倍数
    用辗转相除法，计算target是否x和y的最大公约数（Greatest Common Divisor）的倍数
    */
   	int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool canMeasureWater1(int x, int y, int target) {
        if (x + y < target) {
            return false;
        }
        return (target % gcd(x, y)) == 0;
    }

    // 法2：dfs + 记忆化搜素
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) {
            return false;
        }

        // false表示未走过这个分支
        vector<vector<bool>> memo(x+1, vector<bool>(y+1, false));
        
        std::function<bool(int,int)> dfs = [&](int cur_x, int cur_y) {
            if (memo[cur_x][cur_y] == true)
                return false;
            if (cur_x == target
                || cur_y == target
                || cur_x + cur_y == target) {
                return true;
            }
            memo[cur_x][cur_y] = true; // 表示走过这个分支，但不行

            return dfs(x, cur_y)    // 倒满x 
                || dfs(cur_x, y)    // 倒满y
                || dfs(0, cur_y)    // 倒空x
                || dfs(cur_x, 0)    // 倒空y
                || dfs(cur_x - (min(y, cur_y + cur_x) - cur_y), min(y, cur_y + cur_x))  // x倒给y
                || dfs(min(x, cur_x + cur_y), cur_y - (min(x, cur_x + cur_y)- cur_x)); // y倒给x
        };
        return dfs(x, y);
    }


int main()
{
	bool ans = canMeasureWater(21, 6, 15);
	cout << ans << endl;
	

	return 0;
}
