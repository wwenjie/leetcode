#include<iostream>
#include<vector>

using namespace std;

vector<vector<string>> partition(string s);
void dfs(const string& s, int start);

int main() {
    string s = "aabcb";
	cout<<s<<endl;
    vector<vector<string>> res;
    
    res = partition(s);
    for (auto ve: res){
        for(string st: ve){
            cout<<st<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

vector<vector<int>> f;
vector<vector<string>> res;
vector<string> temp;

vector<vector<string>> partition(string s)
{
	int n = s.length();
	f.assign(n, vector<int>(n, true));	
	
	// 动态规划
	for (int i=n-1; i>=0; --i){
		for(int j=i+1; j<n; ++j) {
			f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
		}
	}

	// for (auto ve: f){
    //     for(auto val: ve) {
    //         cout<<val;
    //     }
    //     cout<<endl;
	// }

	// dfs回溯法
	dfs(s, 0);

    return res;
}

void dfs(const string& s, int start){
	if(start == s.length()) {
		res.push_back(temp);
		return;
	}
	for(int end=start; end<s.length(); end++){
		if(f[start][end]){
			temp.push_back(s.substr(start, end-start+1));
			dfs(s, end+1);
			temp.pop_back();
		}
	}
}
