// 仅用哈希表

const int L = 10

vector<string> findRepeatedDnaSequences(string s) {
	vector<string> ans;
	unordered_map<string, int> cnt;
	int len = s.length();
	for(int i=0; i<len-L; i++){
		string sub = s.substr(i, L);
		if (++cnt[sub] == 2){
			ans.push_back(sub);
		}
	}
	return ans;
}
