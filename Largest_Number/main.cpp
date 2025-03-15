#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string largestNumber(vector<int>& nums);
static bool cmp(const string& a, const string& b); 

int main() {
	// vector<int> nums = {10,2,9,39,17};
	// vector<int> nums = {34323,3432};
	// vector<int> nums = {0,0,0,0};
	vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	string res = largestNumber(nums);
	cout<<res<<endl;

	return 0;
}


string largestNumber(vector<int>& nums) {
    string res;
	int size = nums.size();
    vector<string> strs(size);
    for (int i=0; i<size; i++){
        strs[i] = to_string(nums[i]);
    }

    sort(strs.begin(), strs.end(), cmp);
    for(string& str: strs) {
        res += str;
    }
	// 消去前面的0
	// 如果全是0，则保留一个0
	int idx = 0;
	while(res[idx] == '0' && idx < res.length() - 1) {
		idx++;
	}
	if (idx > 0)
		res = res.substr(idx, res.length() - idx);
    return res;
}

static bool cmp(const string& a, const string& b) {
    string ab(a+b);
    string ba(b+a);
	// TODO 不知道为什么改成>=，会有奇怪报错
    return ab > ba;
}

//struct cmp{
//	bool operator()(const string& a, const string& b)const{
//		string ab = a + b;
//		string ba = b + a;
//		return ab > ba;
//	}//注意这个比较函数
//};
