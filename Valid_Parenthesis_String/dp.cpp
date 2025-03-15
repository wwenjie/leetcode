#include<iostream>
#include<vector>
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
		int len = s.length();
    	vector<vector<bool>> dp(len, vector<bool>(len, false));
    	for(int i=0; i<len; i++){
    	    if (s[i] == '*')
    	        dp[i][i] = true;
    	}
    	for(int i=0; i<len-1; i++){
    	    char c1 = s[i];
    	    char c2 = s[i+1];
    	    if((c1 == '(' || c1 == '*') &&
    	            (c2 == ')' || c2 == '*')){
    	        dp[i][i+1] = true;
    	    }
    	}
    	for(int i=len-3; i>=0; i--){
    	    for(int j=i+2; j<len; j++){
    	        if((s[i] == '(' || s[i] == '*') && (s[j] == ')' || s[j] == '*')) {
    	            // 2端有效
    	            dp[i][j] = dp[i+1][j-1];
    	        }
				for(int k=i; k<j && !dp[i][j]; k++){
					dp[i][j] = dp[i][k] && dp[k+1][j];
				}
    	    }
    	}
    	return dp[0][len-1];
}
