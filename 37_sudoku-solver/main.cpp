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
    /*
    dfs + 回溯
    */
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9);
        vector<int> column(9);
        vector<vector<int>> grid(3, vector<int>(3));

        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                row[i] = row[i] | (1 << num); 
                column[j] = column[j] | (1 << num);
                grid[i/3][j/3] = grid[i/3][j/3] | (1 << num);
            }
        }
        
        vector<vector<char>> new_board = board;
        std::function<bool(int,int)> dfs =[&](int x, int y) {
            // 从(x,y)下标开始找，找到最近的为'.'的下标
            bool full = true;
            for (int i=x; i<9; ++i) {
                for (int j=(i==x?y:0); j<9; ++j) {
                    if (new_board[i][j] == '.') {
                        x = i;
                        y = j;
                        full = false;
                        break;
                    }
                }
                if (!full)
                    break;
            }
            if (full) {
                // 已填满
                cout << "full---->>" << endl;
                return true;
            }
            cout << "0---->>" << x << ", " << y << endl;

            
            for (int num=1; num<=9; ++num) {
                if ((row[x] & (1 << num)) == 0
                        && (column[y] & (1 << num)) == 0
                        && (grid[x/3][y/3] & (1 << num)) == 0) {
                    cout << "1------->>>" << endl;
                    new_board[x][y] = '0' + num;
                    row[x] = row[x] | (1 << num);
                    column[y] = column[y] | (1 << num);
                    grid[x/3][y/3] = grid[x/3][y/3] | (1 << num);
                    bool res = dfs(x, y);
                    if (res)
                        return true;
                    else {
                        new_board[x][y] = '.';
                        row[x] = row[x] ^ (1 << num);
                        column[y] = column[y] ^ (1 << num);
                        grid[x/3][y/3] = grid[x/3][y/3] ^ (1 << num);
                    }
                }    
            }
            return false;
        };
        dfs(0, 0);
        board = new_board;
        return;
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    solution.solveSudoku(board);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    print_vector2(board);
    cout << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    size_t a = 10;
    size_t b = 11;
    cout << ((int)a-(int)b) << endl;
    return 0;
}
