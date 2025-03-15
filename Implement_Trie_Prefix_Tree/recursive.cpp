// 递归实现，108ms，击败7.26%

class Trie {
private:
    vector<Trie*> children = vector<Trie*>(26, nullptr);
    bool is_end = false; // 插入apple和applepen，判断是否存在apple
public:
    Trie() {}
    //Trie(): children(26, nullptr) { }
    /*
    Trie() {
        children = vector<Trie*>(26, nullptr);
    }
    */
    
    void insert(string word) {
        if (word.size() == 0){
            is_end = true;
            return;
        }
        char c = word[0];
        if (children[c-'a'] != nullptr) {
            children[c-'a']->insert(word.substr(1));
            return;
        }
        Trie* node = new Trie();
        node->insert(word.substr(1));
        children[c - 'a'] = node;
    }
    
    bool search(string word) {
        if (word.size() == 0)
            return is_end ? true : false;
        char c = word[0];
        if (children[c - 'a'] == nullptr){
            return false;
        }
        return children[c - 'a']->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if(prefix.size() == 0)
            return true;
        char c = prefix[0];
        if(children[c - 'a'] == nullptr){
            return false;
        }
        return children[c - 'a']->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
