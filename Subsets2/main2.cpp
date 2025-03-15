#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums); 
void dfs(vector<int>& nums, int idx); 


vector<vector<int>> res;
vector<int> temp;

int main() {
	vector<int> nums = {1,2,2,2};
	subsets(nums);

	for (auto ve: res) {
		for(auto num: ve) {
			cout<<num<<" ";
		}
		cout<<endl;
	}
	return 0;
}

vector<vector<int>> subsets(vector<int>& nums) {
    dfs(nums, 0);
    return res;
}

void dfs(vector<int>& nums, int idx) {
    res.push_back(temp);

    for(int i=idx; i< nums.size(); i++) {
        temp.push_back(nums[i]);
        dfs(nums, i+1);
        temp.pop_back();
		while(i+1 < nums.size() && nums[i] == nums[i+1]) 
			++i;
    }
}
