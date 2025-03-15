#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>// 包含 std::sort
#include <limits.h> // 包含 INT_MAX
#include <chrono>
#include <numeric> // 包含 std::accumulate
using namespace std;

class Solution {
public:
    // 法1：栈
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return false;
        if (preorder.size() == 1)
            return preorder[0] == '#';
        vector<string> vec_str = splitString(preorder, ',');
        std::stringstream ss;
        for (string& st: vec_str) {
            ss << st << ",";
        }
        cout << "1--->> " << ss.str() << endl;
        vector<int> vec;
        for (const string& st : vec_str) {
            if (st == "#")
                vec.push_back(-1);
            else
                vec.push_back(std::stoi(st));
        }

        ss.str("");
        for (string& st: vec_str) {
            ss << st << ",";
        }
        cout << "2--->> " << ss.str() << endl;

        int n = vec.size();
        vector<int> stk(n,-2);
        stk[0] = vec[0];
        stk[1] = vec[1];
        int top = 1;
        for (int i=2; i<n; ++i) {
            ++top;
            stk[top] = vec[i];

            std::stringstream ss2;
            for (int st : stk)
            {
                ss2 << st << ",";
            }
            cout << "4--->> " << i << " - " << top << " - " << ss2.str() << endl;

            while (top-2 >=0 && stk[top-2] != -1 && stk[top-1] == -1 && stk[top] == -1) {
                stk[top] = -2;
                stk[top-1] = -2;
                stk[top-2] = -1;
                top-=2;

                std::stringstream ss1;
                for (int st : stk)
                {
                    ss1 << st << ",";
                }
                cout << "5--->> " << i << " - "<< top << " - " << ss1.str() << endl;
            }
        }

        ss.str("");
        for (int st: stk) {
            ss << st << ",";
        }
        cout << "3--->> " << top << " - " << ss.str() << endl;

        return top==0 && stk[top] == -1;
        // return stk.empty();
    }

    std::vector<std::string> splitString(const std::string& input, char delimiter) {  
        std::vector<std::string> tokens;  
        std::string token;  
        std::istringstream iss(input);  
        while (std::getline(iss, token, delimiter)) {  
            tokens.push_back(token);  
        }  
        return tokens;  
    }  

    // 法2：计算入度出度
};

int main()
{
    Solution solution;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    // string preorder = "1,#";
    //string preorder = "9,#,#,1";

    auto start = std::chrono::high_resolution_clock::now();
    bool ans = solution.isValidSerialization("");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;
    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
