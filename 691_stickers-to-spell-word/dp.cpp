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

// 法3 动态规划 + 状态压缩(标案)
// 实际还是dfs + 状压
int minStickers(vector<string> &stickers, string target)
{
    int n = target.size();
    vector<int> dp(1 << n, -1);
    dp[0] = 0;

    // 自顶向下
    std::function<int(int)> helper = [&](int mask)
    {
        if (dp[mask] != -1)
        {
            return dp[mask];
        }

        // 初始化一个不该存在的较大值,INT_MAX也可,有解的情况最大只能为n
        dp[mask] = n + 1;
        for (string &sticker : stickers)
        {
            int new_mask = mask;
            vector<int> cnt(26);
            for (char &ch : sticker)
            {
                cnt[ch - 'a']++;
            }

            // 遍历target每一位
            for (int i = 0; i < n; ++i)
            {
                if ((mask & (1 << i)) > 0 && cnt[target[i] - 'a'] > 0)
                {
                    cnt[target[i] - 'a']--;
                    new_mask ^= (1 << i);
                }
            }

            if (new_mask < mask)
            {
                dp[mask] = min(dp[mask], helper(new_mask) + 1);
            }
        }
        return dp[mask];
    };

    int res = helper((1 << n) - 1);
    return res > n ? -1 : res;
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
