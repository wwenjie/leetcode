#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int>& nums);

int main() {
	vector<int> nums = {1,3,2,4,7,6,1};
	for (int n : nums){
		cout<<n;
	}
	cout<<endl;

	nextPermutation(nums);

	for (int n : nums){
		cout<<n;
	}
	cout<<endl;
	return 0;
}


void nextPermutation(vector<int>& nums) {
    // 1324761 -> 1326147
    // 主要是找到规律，从后开始，先找到nums[i] > nums[i+1]的数，再找i后面比nums[i]大的最小的数，交换，再把下标i后面的数字reverse，以保证后面的数从小到大。
    int i = nums.size() - 2;
    while( i >= 0 and nums[i] >= nums[i+1]){
        i--;
    }

    // 全部数字从大到小排列，reverse即可
    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int j = nums.size() - 1;
    while(j > i && nums[i] >= nums[j]){
        j--;
    }

    swap(nums[i], nums[j]);

    reverse(nums.begin() + i + 1, nums.end());
}
