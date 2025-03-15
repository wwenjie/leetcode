class Solution {
public:
    Solution(int m, int n) {
        srand(time(nullptr));
        this->m = m;
        this->n = n;
        this->total = m * n;
    }
    
    vector<int> flip() {
        int x = rand() % total;
        total--;
        vector<int> ans;
        // 查找位置x对应的映射
        if (map.count(x))
            ans = {map[x] / n, map[x] % n};
        else
            ans = {x / n, x % n};

        // 将位置x对应的银蛇设置为total对应的映射
        if (map.count(total))
            map[x] = map[total];
        else
            map[x] = total;

        return ans;
    }
    
    void reset() {
        map.clear();
        total = m * n;
    }
private:
    int m;
    int n;
    int total;
    unordered_map<int, int> map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
