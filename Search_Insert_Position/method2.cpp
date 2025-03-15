#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target);

int main() {
	int target = 4; // 4,5,7
	vector<int> nums = {1,3,5,6};
	int res = searchInsert(nums, target);
	cout<<res<<endl;
	return 0;
}


int searchInsert(vector<int>& nums, int target) {
	int size = nums.size();
	int l = 0;
	int r = size - 1;
	int mid;
	int res = size;
	while(l < r) {
		// TODO 这是什么新颖做法？！
		// 答：只是相当于 (r - l) / 2 + l，没啥特别
		// int mid = ((r - l) >> 1 ) + l;
		mid = (l + r) / 2;

		if (target <= nums[mid]) {
			r = mid - 1;
			res = mid;
		}
		else {
			l = mid + 1;
		}
	}

	return res;
}
