#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cmath>     // 包含 pow
#include <functional>
#include <algorithm>// 包含 std::sort
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric>  // 包含 std::accumulate
#include "../util/util.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int first_positive_idx = 0;
        int l = 0;
        int r = n-1;
        if (nums[0] > 0) {
            first_positive_idx = 0;
        }
        else if (nums[n-1] <= 0) {
            first_positive_idx = n;
        }
        else {
            while (l < r) {
                int pivot = l + (r-l) / 2;
                if (nums[pivot] > 0 && nums[pivot-1] <= 0) {
                    //first_positive_idx = pivot;
                    r = pivot;
                    cout << "111---->>> l:" << l << "," << ",r:" << r << ",pivot:" << pivot << endl;;
                    break;
                }
                if (nums[pivot] > 0) {
                    cout << "222---->>> l:" << l << "," << ",r:" << r << ",pivot:" << pivot << endl;
                    r = pivot - 1;
                }
                else {
                    cout << "333---->>> l:" << l << "," << ",r:" << r << ",pivot:" << pivot << endl;
                    l = pivot + 1;
                }
            }
            cout << "l:" << l << ",r:" << r << endl;
        }
        l = r - 1;
            cout << "l:" << l << ",r:" << r << endl;

        vector<int> res(n);
        int idx = 0;
        while (l >= 0 && r < n) {
            if (abs(nums[l]) < abs(nums[r])) {
                res[idx] = pow(nums[l], 2);
                l--;
            }
            else {
                res[idx] = pow(nums[r], 2);
                r++; 
            }
            idx++;
            cout << "aaaa" << endl;
        }
        while (l >= 0) {
            res[idx++] = pow(nums[l--], 2);
            cout << "bbbb" << endl;

        }
        while (r < n) {
            res[idx++] = pow(nums[r++], 2);
            cout << "ccccc" << endl;

        }
        return res;
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<int> nums = {-10000,-9999,-7,-5,0,0,10000};
    vector<int> ans = solution.sortedSquares(nums);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    std::stringstream ss;
    for (int i=0; i<ans.size(); ++i) {
        ss << ans[i] << ",";
    }
    cout << "ans:" << ss.str() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;
    return 0;
}
