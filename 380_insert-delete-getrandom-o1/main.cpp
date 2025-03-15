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
#include <random>
#include "../util/util.h"

using namespace std;

class RandomizedSet {
private:
    unordered_set<int> uset;

public:
    RandomizedSet() {
        uint t = (unsigned)time(NULL);
        cout << "t--->>" << t << endl; 
        srand(t);
    }
    
    bool insert(int val) {
        if (uset.count(val)) {
            return false;
        }
        uset.insert(val);
        return true;
    }
    
    bool remove(int val) {
        return uset.erase(val);
    }
    
    int getRandom() {
        // 创建随机数引擎和分布
        std::random_device rd;  // 随机数设备，用于获取种子
        std::mt19937 gen(rd()); // 以随机设备作为种子的Mersenne Twister生成器
        std::uniform_int_distribution<> dis(0, uset.size() - 1); // 均匀分布的整数

        // 生成随机索引
        size_t random_index = dis(gen);

        // 使用随机索引访问 unordered_set 的元素
        // 注意：unordered_set 是无序的，因此我们需要遍历容器来获取随机索引对应的元素
        auto it = uset.begin();
        std::advance(it, random_index); // 移动迭代器到随机位置
        return *it;
    }
    int getRandom_2() {
        // 构造函数那里srand((unsigned)time(NULL))，相同的时间戳种子，产生的一批随机数是一样的。
        int random_index = rand() % uset.size();
        auto it = uset.begin();
        std::advance(it, random_index); // 移动迭代器到随机位置
        return *it;
    }
};


int main()
{
    // Solution solution;

    auto start = std::chrono::high_resolution_clock::now();

    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->insert(2);
    bool param_3 = obj->insert(3);
    bool param_4 = obj->insert(4);
    obj->insert(5);
    obj->insert(6);
    obj->insert(7);
    obj->insert(8);
    obj->insert(9);
    bool param_5 = obj->remove(5);
    int ans = obj->getRandom();
    cout << ans << endl;
    ans = obj->getRandom();
    cout << ans << endl;
    ans = obj->getRandom();
    cout << ans << endl;
    ans = obj->getRandom();
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> elapsed_time = end - start;

    cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    return 0;
}
