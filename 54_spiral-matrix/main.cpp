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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int i=0, j=0;
        int turn = 1;
        while(res.size() < m * n) {
            cout << i << "," << j  << "   " << matrix[i][j]<< endl;
            res.push_back(matrix[i][j]);
            // 判断是否转向
            switch(turn) {
                case 1:
                    // 右上角往左下斜线的元素都要转向
                    if (i == n-j-1)
                        turn = 2;
                    break;
                case 2:
                    // 右下角往左上斜线的元素都要转向
                    if (m-i == n-j) 
                        turn = 3;
                    break;
                case 3:
                    // 左下角往右上斜线的元素都要转向
                    if (m-i-1 == j)
                        turn = 4;
                    break;
                case 4:
                    // matrix[1][0]往右下斜线的元素都要转向
                    if (i == j+1)
                        turn = 1;
                    break;
                default:
                    cout << endl;
            }
            // 选择下个元素
            switch(turn) {
                case 1:
                    j++;
                    break;
                case 2:
                    i++;
                    break;
                case 3:
                    j--;
                    break;
                case 4:
                    i--;
                    break;
                default:
                    cout << endl;
            }
        }
        return res;
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    vector<int> ans = solution.spiralOrder(matrix);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    print_vector(ans);
    cout << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    size_t a = 10;
    size_t b = 11;
    cout << ((int)a-(int)b) << endl;
    return 0;
}
