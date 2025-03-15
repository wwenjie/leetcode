#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums); 

int main() {
	vector<int> nums = {1,2,2,2};
	vector<vector<int>>res = subsetsWithDup(nums);

	for (auto ve: res) {
		for(auto num: ve) {
			cout<<num<<" ";
		}
		cout<<endl;
	}
	return 0;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res(1);

    sort(nums.begin(), nums.end());
    int last_num = INT_MAX;
    int size = 0;
    for(int i=0; i<nums.size(); i++) {
        int new_size = res.size();
        if (nums[i] != last_num){
            size = new_size;
            last_num = nums[i];
        }

        for(int j=new_size-size; j<new_size; j++) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}
