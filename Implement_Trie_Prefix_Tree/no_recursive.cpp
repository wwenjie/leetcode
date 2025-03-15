// 非递归，60ms，击败52%

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
        Trie* node = this;
        for(char ch: word){
            ch -= 'a';
            if(node->children[ch] == nullptr)
                node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        auto node = this;
        for(char ch: word){
            ch -= 'a';
            if(node->children[ch] == nullptr){
                return false;
            }
            node = node->children[ch];
        }
        return node->is_end ? true : false;
    }
    
    bool startsWith(string prefix) {
        auto node = this;
        for(char ch: prefix){
            ch -= 'a';
            if(node->children[ch] == nullptr){
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
