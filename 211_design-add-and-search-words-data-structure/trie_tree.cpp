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
#include "../util/util.h"

using namespace std;


struct TrieNode {
    bool is_end = false;
    TrieNode* childs[26] = {nullptr};
    TrieNode() {
        for (int i = 0; i < 26; ++i) {  
            childs[i] = nullptr;  
        }  
    }
};

class WordDictionary {
private:
    TrieNode root;
    void add(TrieNode* node, const string& word, int idx) {
        if (idx >= word.size()) {
            node->is_end = true;
            return;
        }
        char ch = word[idx];
        if (node->childs[ch - 'a'] == nullptr) {
            node->childs[ch - 'a'] = new TrieNode();
        }
        add(node->childs[ch - 'a'], word, idx+1);
    }
    bool search(TrieNode* node, const string& word, int idx) {
        if (idx >= word.size())
            return node->is_end;
        char ch = word[idx];
        if (ch == '.') {
            for (TrieNode* child: node->childs) {
                if (child == nullptr)
                    continue;
                if (search(child, word, idx+1))
                    return true;
            }
            return false;
        }
        else {
            if (node->childs[ch - 'a'] == nullptr)
                return false;
            return search(node->childs[ch-'a'], word, idx+1);
        }
    }
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        add(&root, word, 0);
    }
    
    bool search(string word) {
        if (word.empty())
            return true;
        return search(&root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    // Solution solution;
    // // vector<int> nums = {4,2,1,4,3,4,5,8,15};
    // vector<int> nums = {7,4,5,1,8,12,4,7};

    // auto start = std::chrono::high_resolution_clock::now();
    // int ans = solution.lengthOfLIS(nums, 5);
    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double, std::micro> elapsed_time = end - start;
    // cout << "ans:" << ans << ", time:" << (elapsed_time.count() / 1000) << "ms" << endl;

    WordDictionary* obj = new WordDictionary();
    obj->addWord("at");
    obj->addWord("and");
    obj->addWord("an");
    obj->addWord("add");
    bool ans = obj->search("a");
    cout << "ans: " << ans << endl;
    ans = obj->search(".at");
    cout << "ans: " << ans << endl;
    obj->addWord("bat");
    ans = obj->search(".at");
    cout << "ans: " << ans << endl;
    ans = obj->search("an.");
    cout << "ans: " << ans << endl;
    ans = obj->search("a.d.");
    cout << "ans: " << ans << endl;
    ans = obj->search("b.");
    cout << "ans: " << ans << endl;
    ans = obj->search("a.d");
    cout << "ans: " << ans << endl;
    ans = obj->search(".");
    cout << "ans: " << ans << endl;


    // ans = obj->book(15, 25);
    // cout << "ans: " << ans << endl;

    return 0;
}





