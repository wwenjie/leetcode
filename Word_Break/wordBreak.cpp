#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

// dp,记忆化搜索

bool wordBreak(string s, vector<string>& wordDict); 

int main() {
	string s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	bool ans = wordBreak(s, wordDict);	
	cout<<ans<<endl;
	return 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> wordSet = unordered_set<string>();
	int maxLen = 0;
	for(auto& word: wordDict) {
		wordSet.insert(word);
		maxLen = max(maxLen, int(word.length()));
	}

	int len = s.size();
	vector<bool> dp = vector<bool>(len + 1);
	dp[0] = true;
	for(int r=1; r<=len; r++) {
		for(int l=r-1; l>=0 && l>=r-maxLen; l--){
			// 检查s[l..r]是否存在wordSet中
			if(dp[l] && wordSet.find(s.substr(l, r-l)) != wordSet.end()) {
				dp[r] = true;
				break;
			}
		}
		
	}
	return dp[len];
}
