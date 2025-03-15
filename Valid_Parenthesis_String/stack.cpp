#include<iostream>
#include <stack>
#include<string>

using namespace std;

bool checkValidString(string s); 

int main() {
	bool ans = checkValidString("(*))");
	cout<<ans<<endl;
	ans = checkValidString("(*)");
	cout<<ans<<endl;
	return 0;
}

bool checkValidString(string s) {
	stack<int> leftStack;
	stack<int> asteriskStack;
	int len = s.size();

	for(int i=0; i<len; i++) {
		char c = s[i];
		if(c == '(')
			leftStack.push(i);
		else if(c == '*'){
			asteriskStack.push(i);
		}
		else { // ')'
			if (!leftStack.empty()) 
				leftStack.pop();
			else if(!asteriskStack.empty()) 
				asteriskStack.pop();
			else
				return false;
		}
	}

	// ')'都被消去，而还有'('和'*'剩下的情况
	while (!leftStack.empty() && !asteriskStack.empty()) {
		int leftIndex = leftStack.top();
		leftStack.pop();
		int asteriskIndex = asteriskStack.top();
		asteriskStack.pop();
		if (leftIndex > asteriskIndex)
			// 出现 "*("的情况就是有问题
			return false;

	}
	return leftStack.empty();
}
