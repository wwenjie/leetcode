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
    string simplifyPath(string path) {
        vector<string> paths;
        vector<string> tmp;
        //boost::split(paths, path, std::is_any_of("/"));
        mySplit(paths, path, '/');
        cout << "size : "<< paths.size() << endl;
        int n = paths.size();
        // if (paths[0] != "/" ) {
        //     tmp.emplace_back("/");
        // }
        for (int i=0; i<n; ++i) {
            if (!tmp.empty() && paths[i] == "..") {
                tmp.pop_back();
            }
            else {
                tmp.push_back("/" + paths[i]);
            }
        }

        // if (!tmp.empty() && tmp.back() == "/") {
        //     tmp.pop_back();
        // }
        string ans;
        for (const string& str: tmp) {
            ans += str;
        }
        return ans;
    }

    void mySplit(vector<string>& output, const string& input, char delimiter) {
        std::istringstream iss(input);
        string token;
        while (std::getline(iss, token, delimiter)) {
            cout << "split --->>> " << token << endl;
            if (!token.empty())
                output.push_back(token);
        }
    }
};


int main()
{
    Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    string ans = solution.simplifyPath("/home//foo/");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
