#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<math.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s);
int char_to_num(char c);
const int LEN = 10;

int main(){
	auto ans = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (auto& v: ans)
		cout<<v<<endl;
	return 0;
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    unordered_map<int, int> umap;
    int size = s.size();
    int a = 4;
    int num = 0;
    for(int i=0; i<LEN; i++){
        int temp = (pow(a, LEN - 1 - i) * char_to_num(s[i]));
        num += temp;
    }
    umap[num] = 1;
    for(int i=LEN; i<size; i++){
        num -= ( pow(a, LEN-1) * char_to_num(s[i-LEN]) );
        num *= a;
        num += char_to_num(s[i]);
        if (++umap[num] == 2){ // 这里相当于，如果umap[num]不存在则赋值为0
            ans.emplace_back(s.substr(i-LEN+1, LEN));
        }
    }
    return ans;
}

int char_to_num(char c){
    if (c == 'A')
        return 0;
    else if (c == 'C')
        return 1;
    else if (c == 'G')
        return 2;
    else if (c == 'T')
        return 3;
    else 
        return 3;
}
