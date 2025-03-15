#include<iostream>
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
	int minCnt = 0, maxCnt = 0;
	int size = s.size();
	for(int i=0; i<n; i++){
		char c = s[i];
		if(c == '('){
			minCnt++;
			maxCnt++;
		}
		else if (c == ')'){
			minCnt = max(minCnt-1, 0);
			maxCnt--;
			if (maxCnt < 0)
				return false;
		}
		else {// '*'
			minCnt = max(minCnt-1, 0)
			maxCnt++;
		}
	}
	return minCnt == 0;
}
