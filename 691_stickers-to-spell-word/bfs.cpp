#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <functional>
#include <limits.h>
#include <chrono>  
using namespace std;

// 法2 状态压缩 + bfs + 动态规划
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

    for (const char &ch : target)
    {
        if (!sticker_char_set.count(ch))
            return -1;
    }

    int n = target.size();
    vector<int> dp((1 << n), 0); // 表示state状态所需最少贴纸数
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        int state = que.front();
        que.pop();
        for (vector<int> char_cnt : sticker_char_cnt)
        {
            int new_state = state;
            for (int i = 0; i < target.size(); ++i)
            {
                //cout<< "11-------->> " << i << "," << new_state << "," << char_cnt[target[i] - 'a'] << endl;

                if ((new_state & (1 << i)) == 0 && char_cnt[target[i] - 'a'] > 0)
                {
                    char_cnt[target[i] - 'a']--;
                    new_state |= (1 << i);
                    //cout<< "22-------->>"  << endl;
                }
            }
            if (new_state == state || dp[new_state] > 0)
                //cout<< "11-------->>" << new_state << "," << state << "," << dp[new_state] << endl;
                continue;
            que.push(new_state);
            dp[new_state] = dp[state] + 1;
            if (new_state == (1 << n) - 1)
                return dp[new_state];
        }
    }
    return -2;
}

int main()
{
    //vector<string> stickers = {"this","island","keep","spring","problem","subject"};
    //vector<string> stickers = {"this","island","spring","problem"};
    // vector<string> stickers = {"island","spring","problem"};
    // string target = "gasproper";

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
