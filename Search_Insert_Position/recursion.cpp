#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target);
int binSearch(vector<int>& nums, int target, int l, int r);

int main() {
	int target = 7;
	vector<int> nums = {1,3,5,6};
	int res = searchInsert(nums, target);
	cout<<res<<endl;
	return 0;
}


int searchInsert(vector<int>& nums, int target) {
    return binSearch(nums, target, 0, nums.size() - 1);
}

int binSearch(vector<int>& nums, int target, int l, int r){
    if (nums[l] == target) {
        return l;
    }
    if (l == r){
		if (target < nums[l])
			return l;
		else
			return l+1;
    }

    int k = (l + r) / 2;
    int res;
    if (target <= nums[k])
        return binSearch(nums, target, l, k);
    else
        return binSearch(nums, target, k+1, r);
}
