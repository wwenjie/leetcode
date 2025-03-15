#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isInterleave(string s1, string s2, string s3);

int main() {
	bool res = isInterleave("aabcc", "dbbca", "aadbbcbcac");
	cout<<res<<endl;
	return 0;
}

bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    if (len1 + len2 != len3)
        return false;
    vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
	dp[0][0] = true;

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
			if(i==0 && j==0)
				continue;
            bool res1=false;
            bool res2=false;
            if ( i-1 >= 0 && dp[i-1][j] == true && s1[i-1] == s3[i+j-1]){
                res1 = true;
            }
            else if (j-1 >= 0 && dp[i][j-1] == true && s2[j-1] == s3[i+j-1]){
                res2 = true;
            }
            
            dp[i][j] = res1 || res2;
        }
    }
    return dp[len1][len2];
}

// 标准答案
bool isInterleave2(string s1, string s2, string s3) {
    auto f = vector < vector <int> > (s1.size() + 1, vector <int> (s2.size() + 1, false));

    int n = s1.size(), m = s2.size(), t = s3.size();

    if (n + m != t) {
        return false;
    }

    f[0][0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
            }
            if (j > 0) {
                f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }

    return f[n][m];
}
