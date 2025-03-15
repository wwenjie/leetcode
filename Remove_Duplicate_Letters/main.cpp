#include<iostream>
#include<string>
#include<vector>

using namespace std;

string removeDuplicateLetters(string s);

int main() {
	string s = "cbacdcbc";
	string ans = removeDuplicateLetters(s);
	cout<<ans<<endl;
	return 0;
}

string removeDuplicateLetters(string s) {
	string stk;
	vector<int> visit(26, 0);
	vector<int> num(26, 0);
	for(char ch: s){
		num[ch - 'a']++;
	}

	for(char ch : s){
		if (!visit[ch - 'a']) {
			while(!stk.empty() && stk.back() > ch && num[stk.back() -'a'] > 0){
				visit[stk.back() - 'a'] = 0;
				stk.pop_back();
			}
			stk.push_back(ch);
			visit[ch - 'a'] = 1;

		}
		num[ch - 'a'] -=1;
	}
	return stk;
}
