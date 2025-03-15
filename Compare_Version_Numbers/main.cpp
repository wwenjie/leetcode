#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> split(string str, string pattern); 
int compareVersion(string version1, string version2); 

int main() {
	//auto res = split("11.22.34", ".");
	//for(auto& st:res){
	//	cout<<st<<endl;
	//}

	int ans = compareVersion("1.01", "1.001");
	cout<<ans<<endl;

	return 0;
}

vector<string> split(string str, string pattern) {
    string::size_type pos;
    vector<string> ans;
    str += pattern; // 没有这个会分割不到最后一段"34"字符串
    int size = str.size();

    int i = 0;
    while(i < size){
        pos = str.find(pattern, i);
        if(pos < size) {
			// 分割pos之前的字符
            string s = str.substr(i, pos-i);
            ans.push_back(s);
            i = pos + pattern.size();
        }
		else
			break;
    }
    return ans;
}

int compareVersion(string version1, string version2) {
    auto v1 = split(version1, ".");
    auto v2 = split(version2, ".");
    int size1 = v1.size(), size2 = v2.size();
    int idx1 = 0, idx2 = 0;
    int n1, n2;
    while(true) {
        if (idx1 >= size1 && idx2 >= size2){
            return 0;
        }
        else if (idx1 >= size1){
            n1 = 0;
            n2 = atoi(v2[idx2].c_str());
        }
        else if (idx2 >= size2){
            n1 = atoi(v1[idx1].c_str());
            n2 = 0;
        }
        else {
            n1 = atoi(v1[idx1].c_str());
            n2 = atoi(v2[idx2].c_str());
        }
        if (n1 != n2)
            return n1 > n2 ? 1 : -1;
        idx1++;
        idx2++;
    }
    return 0;
}
