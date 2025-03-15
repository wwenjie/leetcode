#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Node {
    int l;      // 左区间位置
    int r;      // 右区间位置
    int val;    // 区间内最值
    int lazy;   // 该区间懒标记
};

// 线段树
class SegmentTree {
private:
    vector<Node*> tree;
    int n;  // 最值
public:
    void build(int) {
        
    }
};