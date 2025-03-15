#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <functional>
#include <limits.h>
#include <chrono>  
using namespace std;

void show_used(const vector<int>& used, int min_cnt) {
    std::stringstream ss;
    for (int cnt : used) {
        ss << cnt << ",";
    }
    cout << "used:[" << ss.str() << "]  , min_cnt:" << min_cnt  << endl;
}

void show_logs(const std::string& pre, const vector<int>& logs, int cnt) {
    return;
    // std::stringstream ss;
    // for (int idx : logs) {
    //     ss << idx << ",";
    // }
    // cout << pre << ",used:[" << ss.str() << "]  , cnt:" << cnt  << endl;
}

// 像是完全背包问题
// 法1 dfs + 记忆化搜索
int minStickers(vector<string> &stickers, string target)
{
    unordered_set<char> sticker_char_set;
    vector<vector<int>> sticker_char_cnt(stickers.size(), vector<int>(26, 0));
    for (int i = 0; i < stickers.size(); ++i)
    {
        string sticker = stickers[i];
        for (const char &ch : sticker)
        {
            sticker_char_cnt[i][ch - 'a'] += 1;
            sticker_char_set.insert(ch);
        }
    }

    vector<int> target_state(26, 0);
    for (const char &ch : target)
    {
        target_state[ch - 'a'] += 1;
    }

    // 检查target是否存在stickers中不存在的字母
    for (const char &ch : target)
    {
        if (!sticker_char_set.count(ch))
        {
            return -1;
        }
    }

    // 使用情况
    // vector<int> used(stickers.size(), 0);
    // 表示target状态时，可使用的最少贴纸数
    map<vector<int>, int> memo;
    // 表示(use_cnt,target)状态时，可使用的最少贴纸数
    map<pair<int, vector<int>>, int> memo2;

    // 测试日志
    vector<int> logs;

    std::function<int(int, vector<int> &)> dfs =
        [&](int cur_cnt, vector<int> &state)
    {
        // used：每张贴纸的使用数量
        // state：target状态
        // if (memo.count(state)) {
        //     show_logs("3======>>>", logs, memo[state]);
        //     return memo[state];
        // }
        if (memo2.count(make_pair(cur_cnt, state))) {
            show_logs("3======>>>", logs, memo2[make_pair(cur_cnt,state)]);
            return memo2[make_pair(cur_cnt, state)];
        }

        bool state_all_0 = true;
        for (int cnt : state)
        {
            if (cnt > 0)
            {
                state_all_0 = false;
                break;
            }
        }
        if (state_all_0)
        {
            // show_used(used, cur_cnt);
            return cur_cnt;
            // int used_sum = 0;
            // for (int cnt : used)
            // {
            //     used_sum += cnt;
            // }
            // return used_sum;
        }

        int min_cnt = INT_MAX;
        for (int i = 0; i < sticker_char_cnt.size(); ++i)
        {
            const vector<int> &char_cnt = sticker_char_cnt[i];
            vector<int> new_state = state;
            for (int j = 0; j < char_cnt.size(); ++j)
            {
                new_state[j] = max(0, new_state[j] - char_cnt[j]);
            }
            if (new_state == state)
            {
                continue;
            }
            //used[i] += 1;
            logs.push_back(i);
            min_cnt = min(min_cnt, dfs(cur_cnt + 1,new_state));
            show_logs("1---->>>", logs, min_cnt);

            logs.pop_back();
            //used[i] -= 1;
        }
        //memo[state] = min_cnt;
        memo2[make_pair(cur_cnt,state)] = min_cnt;
        show_logs("2=====>>>", logs, min_cnt);
        return min_cnt;
    };

    return dfs(0, target_state);
}

int main()
{
    //vector<string> stickers = {"this","island","keep","spring","problem","subject"};
    //vector<string> stickers = {"this","island","spring","problem"};
    //vector<string> stickers = {"island","spring","problem"};
    //string target = "gasproper";

    // vector<string> stickers = {"control","heart","interest","stream","sentence","soil","wonder","them","month","slip","table","miss","boat","speak","figure","no","perhaps","twenty","throw","rich","capital","save","method","store","meant","life","oil","string","song","food","am","who","fat","if","put","path","come","grow","box","great","word","object","stead","common","fresh","the","operate","where","road","mean"};
    // string target = "stoodcrease";

    vector<string> stickers = {"show","process","back","deep","three","dictionary","single","are","such","proper","dress","market","mountain","little","instant","young","written","master","cloud","under","valley","ever","war","sent","plant","string","beauty","thousand","here","dark","rest","off","line","true","grow","change","neck","town","feet","yard","center","liquid","country","arrange","work","hot","record","paragraph","iron","once"};
    string target = "paintwhere";

    auto start = std::chrono::high_resolution_clock::now();
    int ans = minStickers(stickers, target);
    auto end = std::chrono::high_resolution_clock::now(); 

    std::chrono::duration<double, std::micro> elapsed_time = end - start;  
    cout << "ans:" << ans << ", time:" << (elapsed_time.count()/1000) << "ms" << endl;

    return 0;
}
