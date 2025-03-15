#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int prime = 5;
    map<char, int> ch2num = {{'A',1}, {'C',2}, {'G',3}, {'T',4}};
    vector<string> findRepeatedDnaSequences_2(string s) {
        int n = s.size();
        set<string> res;
        map<uint64_t, string> visited;
        uint64_t hash = 0;
        for (int i=0; i<=9; ++i) {
            int num = ch2num[s[i]];
            hash += num * pow(prime, i);
        }
        cout << "hash:" << hash << "," << s.substr(0,10) <<  endl;
        visited[hash] = s.substr(0, 10);
        for (int i=10; i<=n-1; ++i) {
            hash /= prime;
            int num = ch2num[s[i]];
            hash += num * pow(prime, 9);
            cout << "---->> " << i << " , " << hash << "," << s.substr(i-9,10) << endl;
            if (visited.count(hash)) {
                res.insert(visited[hash]);
                res.insert(s.substr(i-9, 10));
            }
            visited[hash] = s.substr(i-9, 10);
        }
        return vector<string>(res.begin(), res.end());
    }

    vector<string> findRepeatedDnaSequences(string s) {
        double prime = 31;
        int n = s.size();
        set<string> res;
        map<double, string> visited;
        uint64_t hash = 0;
        for (int i=0; i<=9; ++i) {
            hash += ((((uint64_t)(s[i] - 'A')) * (uint64_t)pow(prime, i)) );
        }
        visited[hash] = s.substr(0,10);
        cout << "hash:" << hash << "," << s.substr(0,10) <<  endl;

        for (int i=10; i<=n-1; ++i) {
            hash /= prime;
            hash += (((uint64_t)(s[i] - 'A')) * (uint64_t)pow(prime, 9) );
            cout << "---->> " << i << " , " << hash << "," << s.substr(i-9,10) << endl;

            if (visited.count(hash)) {
                res.insert(visited[hash]);
                res.insert(s.substr(i-9, 10));
            }
            visited[hash] = s.substr(i-9, 10);
        }
        return vector<string>(res.begin(), res.end());
    }
};

int main()
{
    Solution solution;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    auto start = std::chrono::high_resolution_clock::now();
    vector<string> ans = solution.findRepeatedDnaSequences(s);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;


    for (string& st: ans) {
        cout << st << endl;
    }

    cout << "ans_size:" << ans.size() << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}





