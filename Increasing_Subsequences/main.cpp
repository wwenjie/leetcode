#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> findSubsequences(vector<int>& nums);
void dfs(vector<int>& nums, int idx);

vector<vector<int>> res;
vector<int> temp;

int main() {
	vector<int> nums = {4,6,7,7};
	vector<vector<int>> res = findSubsequences(nums);
	// 输出
	for(auto& ve: res) {
		for(int num: ve) {
			cout<<num<<" ";
		}
		cout<<endl;
	}
	return 0;
}


vector<vector<int>> findSubsequences(vector<int>& nums){
	dfs(nums, 0);
	return res;
}

void dfs(vector<int>& nums, int idx) {	
	if (idx == nums.size()){
		if (temp.size() >= 2)
			res.push_back(temp);
		return;
	}
	if (temp.empty() || nums[idx] >= temp.back()) {
		temp.push_back(nums[idx]);
		dfs(nums, idx + 1);
		temp.pop_back();
	}
	if (temp.back() != nums[idx])
		dfs(nums, idx + 1);
}
