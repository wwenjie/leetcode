#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums); 

int main() {
	vector<int> nums = {1,2,3};
	vector<vector<int>>res = subsets(nums);

	for (auto ve: res) {
		for(auto num: ve) {
			cout<<num<<" ";
		}
		cout<<endl;
	}
	return 0;
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1); // 先把 空[] 加到子集里
	for(int i=0; i<nums.size(); i++){
		int size = res.size();
		for(int j=0; j<size; j++){
			res.push_back(res[j]);
			res.back().push_back(nums[i]);
		}
	}
    return res;
}
