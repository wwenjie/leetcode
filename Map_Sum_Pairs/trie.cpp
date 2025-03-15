// 字典树

struct TrieNode {
	int val = 0;
	TrieNode * next[26];
	TrieNode() {
		this->val = 0;
		for (int i=0; i<26; ++i){
			this->next[i] = nullptr;
		}
	}
};

class MapSum {
private:
	TrieNode * root;
	unordered_map<string, int> cnt;
public:
	void insert(string key, int val){
		int delta = val;
		if (cnt.count(key)){
			delta -= cnt[key];
		}
		cnt[key] += delta;
		root->val += delta;
		auto* node = root;
		for(char c: key){
			if (node->next[c-'a'] == nullptr){
				node->next[c-'a'] = new TrieNode();
			}
			node = node->next[c-'a'];
			node->val += delta;
		}
	}

	int sum(string key) {
		auto * node = root;
		for(auto c: key){
			node = node->next[c-'a'];
			if (node == nullptr){
				return 0;
			}
		}
		return node.val;
	}
}
