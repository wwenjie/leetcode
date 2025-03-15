#include<iostream>
#include <unordered_map>

using namespace std;

// 我原本用vector<int> count(26*2, 0), 而不是unordered_map，执行效率击败100%

int longestPalindrome(string s);

int main() {
	string s = "abccccdd";
	//string s = "ccc";
	int res = longestPalindrome(s);
	cout<<res<<endl;
	return 0;
}

int longestPalindrome(string s) {
	unordered_map<char, int> count;
	int ans = 0;

	for(char ch: s)
		count[ch]++;
	for(auto p: count){
		int num = p.second;
		ans += num / 2 * 2;
		if (ans % 2 == 0 && num % 2 == 1){
			ans++;
		}
	}
	return ans;
}
