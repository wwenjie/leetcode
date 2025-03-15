#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../util/util.h"


using namespace std;
  
void makeArray(int n, vector<vector<int>>& array) {
    int row = 0;
    int col = (n-1)/2;
    array[row][col] = 1;
    int num = 2; // 下一个要填的数
    int done_flag = false; // 上次循环走到了逻辑分支6
    int done_cnt = 0; // 连续到逻辑分支6的次数
	cout << "start -->>" << endl;
    while (true) {
        //cout << "11111" << endl;
        if (done_flag == false)
            done_cnt = 0;
        else if (done_cnt >= n || num > n * n)
            break;
        done_flag = false;
        if (row == 0 && col == n-1) {
            // 2. col 是最后一列
			cout << "----->" << 2 << endl;
             row++;
            col = n-1;
            array[row][col] = num;
            num++;
        }
        else if (row == 0 && col != n-1) {
            // 3. col 不是最后一列
			cout << "----->" << 3 << endl;

            row = n-1;
            col++;
            array[row][col] = num;
            num++;

        }
        else if (row != 0 && col == n-1) {
            // 4
			row--;
            col = 0;
            array[row][col] = num;
            num++;
        }
        else {
            int new_row = (row-1 >= 0 ? row-1 : n-1 );
            int new_col = (col+1 < n ? col+1 : 0);
            if (array[new_row][new_col] == 0) {
                // 5
				cout << "----->" << 5 << endl;
                array[new_row][new_col] = num;
                row = new_row;
                col = new_col;
                num++;
            }
            else {
                // 6.已经填过
				cout << "----->" << 6 << endl;
                row = (row + 1 < n ? row + 1 : 0);

                // row = new_row + 1;
                // col = new_col;
                done_flag = true;
                done_cnt++;
            }
        }
		cout  << "row:" << row << ",col:" << col << endl;
		print_vector2(array);
    }
}

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }
    int n;
    while (cin >> n) {
        vector<vector<int> > array(n, vector<int>(n, 0));
        makeArray(n, array);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cout << array[i][j] << endl;
            }
        }
    }
}
// 64 位输出请用 printf("%lld")